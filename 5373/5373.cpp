#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;

const int UP = 0;
const int DOWN = 1;
const int FRONT = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;
const int WHITE = 0;
const int YELLOW = 1;
const int RED = 2;
const int ORANGE = 3;
const int GREEN = 4;
const int BLUE = 5;

int A[6][3][3];
vector<pii> flat{ {0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0} };

void init()
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) 
                A[i][j][k] = i;   
}

void rotateFlat(const int& n, const char& c) // 두 방향
{
    if (c == '+') {
        for (int i = 0; i < 2; i++) {
            int last = A[n][flat.back().first][flat.back().second];
            int tmp;
            for (auto& e : flat)
            {
                tmp = A[n][e.first][e.second];
                A[n][e.first][e.second] = last;
                last = tmp;
            }
        }
    }
    else
    {
        for (int i = 0; i < 2; i++) {
            int last = A[n][flat.front().first][flat.front().second];
            int tmp;
            for (int i = 7; i >= 0; i--)
            {
                tmp = A[n][flat[i].first][flat[i].second];
                A[n][flat[i].first][flat[i].second] = last;
                last = tmp;
            }
        }
    }
}

void rotateUp(const char& c)
{
    vector<vector<int>> v(6, vector<int>());
    for (int i = 0; i < 3; i++)
    {
        v[BACK].push_back(A[BACK][0][i]);
        v[RIGHT].push_back(A[RIGHT][0][i]);
        v[FRONT].push_back(A[FRONT][0][i]);
        v[LEFT].push_back(A[LEFT][0][i]);
    }
    for (int i = 0; i < 3; i++)
    {
        A[FRONT][0][i] = c == '+' ? v[RIGHT][i] : v[LEFT][i];
        A[LEFT][0][i] = c == '+' ? v[FRONT][i] : v[BACK][i];
        A[BACK][0][i] = c == '+' ? v[LEFT][i] : v[RIGHT][i];
        A[RIGHT][0][i] = c == '+' ? v[BACK][i] : v[FRONT][i];
    }
}

void rotateDown(const char& c)
{
    vector<vector<int>> v(6, vector<int>());
    for (int i = 0; i < 3; i++) 
    {
        v[FRONT].push_back(A[FRONT][2][i]);
        v[RIGHT].push_back(A[RIGHT][2][i]);
        v[BACK].push_back(A[BACK][2][i]);
        v[LEFT].push_back(A[LEFT][2][i]);
    }
    for (int i = 0; i < 3; i++)
    {
        A[FRONT][2][i] = c == '+' ? v[LEFT][i] : v[RIGHT][i];
        A[LEFT][2][i] = c == '+' ? v[BACK][i] : v[FRONT][i];
        A[RIGHT][2][i] = c == '+' ? v[FRONT][i] : v[BACK][i];
        A[BACK][2][i] = c == '+' ? v[RIGHT][i] : v[LEFT][i];
    }
}

void rotateLeft(const char& c)
{
    vector<vector<int>> v(6, vector<int>());
    for (int i = 0; i < 3; i++) 
    {
        v[UP].push_back(A[UP][i][0]);
        v[FRONT].push_back(A[FRONT][i][0]);
        v[DOWN].push_back(A[DOWN][i][0]);
        v[BACK].push_back(A[BACK][i][2]);   
    }
    for (int i = 0; i < 3; i++)
    {
        A[UP][i][0] = c == '+' ? v[BACK][2 - i] : v[FRONT][i];
        A[FRONT][i][0] = c == '+' ? v[UP][i] : v[DOWN][i];
        A[BACK][i][2] = c == '+' ? v[DOWN][2 - i] : v[UP][2 - i];
        A[DOWN][i][0] = c == '+' ? v[FRONT][i] : v[BACK][2 - i];
    }
}

void rotateRight(const char& c)
{
    vector<vector<int>> v(6, vector<int>());
    for (int i = 0; i < 3; i++) 
    {
        v[UP].push_back(A[UP][i][2]);
        v[FRONT].push_back(A[FRONT][i][2]);
        v[DOWN].push_back(A[DOWN][i][2]);
        v[BACK].push_back(A[BACK][i][0]);  
    }
    for (int i = 0; i < 3; i++)
    {
        A[UP][i][2] = c == '+' ? v[FRONT][i] : v[BACK][2 - i];
        A[FRONT][i][2] = c == '+' ? v[DOWN][i] : v[UP][i];
        A[BACK][i][0] = c == '+' ? v[UP][2 - i] : v[DOWN][2 - i];
        A[DOWN][i][2] = c == '+' ? v[BACK][2 - i] : v[FRONT][i];
    }
}

void rotateFront(const char& c)
{
    vector<vector<int>> v(6, vector<int>());
    for (int i = 0; i < 3; i++)
    {
        v[UP].push_back(A[UP][2][i]);
        v[RIGHT].push_back(A[RIGHT][i][0]);
        v[DOWN].push_back(A[DOWN][0][i]);
        v[LEFT].push_back(A[LEFT][i][2]);
    }
    for (int i = 0; i < 3; i++)
    {
        A[UP][2][i] = c == '+' ? v[LEFT][2 - i] : v[RIGHT][i];
        A[RIGHT][i][0] = c == '+' ? v[UP][i] : v[DOWN][2 - i];
        A[DOWN][0][i] = c == '+' ? v[RIGHT][2 - i] : v[LEFT][i];
        A[LEFT][i][2] = c == '+' ? v[DOWN][i] : v[UP][2 - i];
    }
}

void rotateBack(const char& c)
{
    vector<vector<int>> v(6, vector<int>());
    for (int i = 0; i < 3; i++)
    {
        v[UP].push_back(A[UP][0][i]);
        v[RIGHT].push_back(A[RIGHT][i][2]);
        v[DOWN].push_back(A[DOWN][2][i]);
        v[LEFT].push_back(A[LEFT][i][0]);
    }
    for (int i = 0; i < 3; i++)
    {
        A[UP][0][i] = c == '+' ? v[RIGHT][i] : v[LEFT][2 - i];
        A[LEFT][i][0] = c == '+' ? v[UP][2 - i] : v[DOWN][i];
        A[DOWN][2][i] = c == '+' ? v[LEFT][i] : v[RIGHT][2 - i];
        A[RIGHT][i][2] = c == '+' ? v[DOWN][2 - i] : v[UP][i];
    }
}

void rotate(const string& s)
{
    if (s[0] == 'U') 
    {
        rotateFlat(UP, s[1]);
        rotateUp(s[1]);
    }
    else if (s[0] == 'L')
    {
        rotateFlat(LEFT, s[1]);
        rotateLeft(s[1]);
    }
    else if (s[0] == 'D')
    {
        rotateFlat(DOWN, s[1]);
        rotateDown(s[1]);
    }
    else if (s[0] == 'R')
    {
        rotateFlat(RIGHT, s[1]);
        rotateRight(s[1]);
    }
    else if (s[0] == 'F')
    {
        rotateFlat(FRONT, s[1]);
        rotateFront(s[1]);
    }
    else if (s[0] == 'B')
    {
        rotateFlat(BACK, s[1]);
        rotateBack(s[1]);
    }
}

void display()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x = A[UP][i][j];
            if (x == WHITE) cout << 'w';
            else if (x == YELLOW) cout << 'y';
            else if (x == RED) cout << 'r';
            else if (x == ORANGE) cout << 'o';
            else if (x == GREEN) cout << 'g';
            else cout << 'b';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        init();
        int x; 
        cin >> x;
        while (x--)
        {
            string s;
            cin >> s;
            rotate(s);
        }
        display();
    }
    return 0;
}