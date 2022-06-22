#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    for (int test_case = 1; test_case <= 10; ++test_case)
    {
        int N;

        int arr[102][102];
        int x, y;
        cin >> N;
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == 2) {
                    x = i, y = j;
                }
            }
        }

        while (x != 1) {
            if (arr[x][y - 1] != 1 && arr[x][y + 1] != 1) {
                arr[x][y] = arr[x - 1][y];
                x--;
            }
            else if (arr[x][y - 1] == 1) {
                while (arr[x][y] == 1) {
                    arr[x][y] = arr[x][y - 1];
                    y--;
                }
                arr[x][y] = arr[x][y + 1];
                y++;
                arr[x][y] = arr[x - 1][y];
                x--;
            }
            else if (arr[x][y + 1] == 1) {
                while (arr[x][y] == 1) {
                    arr[x][y] = arr[x][y + 1];
                    y++;
                }
                arr[x][y] = arr[x][y - 1];
                y--;
                arr[x][y] = arr[x - 1][y];
                x--;
            }
        }
        cout << "#" << N << " " << y - 1 << endl;


    }
    return 0;
}