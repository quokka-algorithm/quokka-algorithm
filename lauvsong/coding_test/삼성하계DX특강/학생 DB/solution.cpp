#include<map>
#include<set>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

constexpr int MAX_ID = 1'000'000'000;
constexpr int MAX_GRADE = 3;
constexpr int MAX_GENDER = 2;

map<int, set<int>> db[MAX_GRADE][MAX_GENDER];
map<int, tuple<int, int, int>> loc;   // id - (학년, 성별, 점수)

void init() {
    
    for (int i = 0; i < MAX_GRADE; i++) {
        for (int j = 0; j < MAX_GENDER; j++) {
            db[i][j].clear();
        }
    }
    loc.clear();
}

int get_gender_index(string gender) {
    if (gender == "male") return 0;
    else return 1;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    int gender = get_gender_index(mGender);
    auto& row = db[mGrade-1][gender];

    if (row.empty() || row.find(mScore) == row.end()) {
        row[mScore] = set<int>({mId});
    }
    else {
        row[mScore].insert(mId);
    }

    loc[mId] = { mGrade-1, gender, mScore };

    return *row.rbegin()->second.rbegin();
}

int remove(int mId) {
    if (loc.find(mId) == loc.end()) return 0;

    int x, y, z;
    tie(x, y, z) = loc[mId];

    auto& row = db[x][y];
    row[z].erase(mId);
    loc.erase(mId);

    if (row[z].empty()) {
        row.erase(z);
    }

    if (row.empty()) return 0;
    return *row.begin()->second.begin();
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
    priority_queue<pair<int, int>> pq;

    for (register int x = 0; x < mGradeCnt; x++) {
        int grade = mGrade[x]-1;

        for (register int y = 0; y < mGenderCnt; y++) {
            int gender = get_gender_index(mGender[y]);

            auto& row = db[grade][gender];
            for (auto& iter : row) {
                if (mScore <= iter.first) {
                    pq.push({ iter.first, *iter.second.begin() });
                }
            }
        }
    }

    if (pq.empty()) return 0;
    return pq.top().second;
}