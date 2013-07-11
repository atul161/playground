import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {
    FastScanner in;
    PrintWriter out;

    class Edge {
        int d;
        int s;

        Edge(int d, int s) {
            this.d = d;
            this.s = s;
        }
    }

    int n;
    ArrayList<Edge>[] edges;
    ArrayList<Edge>[] ch;
    int[] sz;

    long[][] C;
    long MOD = 1000000007;

    int dfs(int x, int p) {
        sz[x] = 1;
        for (Edge e : edges[x]) {
            if (e.d != p) {
                ch[x].add(e);
                int v = dfs(e.d, x);
                sz[x] +=  v;
            }
        }
        return sz[x];
    }


    long[][] ans;
    long[][] ltans;
    long[][] gtans;

    void calc(int x) {
        for (Edge e : ch[x]) {
            calc(e.d);
        }

        int nc = ch[x].size();
        int sx = sz[x];

        for (int p = 0; p < sx; p++) {
            long[][] dp = new long[nc + 1][p + 1];
            dp[0][0] = 1;
            int sums = 0;

            for (int i = 0; i < ch[x].size(); i++) {
                int y = ch[x].get(i).d;
                int s = ch[x].get(i).s;
                int sy = sz[y];

                for (int j = 0; j <= p; j++) {
                    if (dp[i][j] == 0) {
                        continue;
                    }
                    if (s == 1) {
                        for (int k = 0; k < sy; k++) {
                            if (j + k + 1 <= p && sx - p - 1 - (sums - j) >= 0) {
                                dp[i + 1][j + k + 1] = (dp[i + 1][j + k + 1] + dp[i][j] * ltans[y][k] % MOD * C[p - j][k + 1] % MOD * C[sx - p - 1 - (sums - j)][sy - k - 1]) % MOD;
                            }
                        }
                    } else {
                        for (int k = 0; k < sy; k++) {
                            if (j + k <= p && sx - p - 1 - (sums - j) >= 0) {
                                dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j] * gtans[y][k] % MOD  * C[p - j][k] % MOD * C[sx - p - 1 - (sums - j)][sy - k]) % MOD;
                            }
                        }
                    }
                }

                sums += sy;
            }

            ans[x][p] = dp[nc][p];
        }

        ltans[x][0] = ans[x][0];
        long sumans = ltans[x][0];
        for (int i = 1; i < sx; i++) {
            ltans[x][i] = (ltans[x][i - 1] + ans[x][i]) % MOD;
            sumans = (sumans + ans[x][i]) % MOD;
        }
        for (int i = 0; i < sx; i++) {
            gtans[x][i] = ((sumans - ltans[x][i] + ans[x][i]) % MOD + MOD) % MOD;
        }
    }

    public void solve() throws IOException {
        C = new long[1001][1001];
        C[0][0] = 1;
        for (int i = 1; i < C.length; i++) {
            C[i][0] = 1;
            for (int j = 1; j < C[i].length; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        int testNo = in.nextInt();
        for (int test = 1; test <= testNo; test++) {
            long start = System.currentTimeMillis();
            int n = in.nextInt();
            edges = new ArrayList[n];
            ch = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new ArrayList<>();
                ch[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; i++) {
                int x = in.nextInt();
                int s = in.next().equals("<") ? -1 : 1;
                int y = in.nextInt();
                edges[x].add(new Edge(y, s));
                edges[y].add(new Edge(x, -s));
            }

            sz = new int[n];
            dfs(0, -1);

            ans = new long[n][n];
            ltans = new long[n][n];
            gtans = new long[n][n];
            calc(0);

            long cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt = (cnt + ans[0][i]) % MOD;
            }
            System.out.println("Case #" + test + ": " + cnt);
            out.println("Case #" + test + ": " + cnt);
            System.out.println(System.currentTimeMillis() - start);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("permutations.txt"));
            out = new PrintWriter(new File("permutations.ans"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new C().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File file) throws IOException {
            br = new BufferedReader(new FileReader(file));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}