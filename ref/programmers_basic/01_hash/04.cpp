#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>


using namespace std;

struct cmp{
    bool operator()(pair<int, int>& a, pair<int,int>& b){
        if(a.second == b.second){
            return a.first > b.first;
        }else{
            return a.second < b.second;
        }
    }
};

/**
 * @brief 
 * 베스트 앨범을 만든다
 * 속한 노래가 많이 재생된 장르를 먼저 수록
 * 장르 내에서 많이 재생된 노래를 먼저 수록
 * 같은 재생횟수라면 고유번호가 낮은 노래를 먼저 수록
 * 
 * 
 * @param genres 장르정보
 * @param plays 재생횟수
 * @return vector<int> 
 */
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int numberOfSongs = plays.size();
    unordered_map<string, priority_queue<pair<int, int>, vector<pair<int,int>>, cmp>> bestAlbumTemp;
    map<string, int> bestGenreTemp;

    for(int i = 0; i < numberOfSongs; ++i){
        if(bestAlbumTemp.find(genres[i]) == bestAlbumTemp.end()){
            bestAlbumTemp[genres[i]].push(make_pair(i, plays[i]));
            bestGenreTemp[genres[i]] = plays[i];
            // bestAlbumTemp.insert(make_pair(genres[i], make_pair(i, plays[i])));
            // bestGenreTemp.insert(make_pair(genres[i], plays[i]));
        }else{
            bestAlbumTemp[genres[i]].push(make_pair(i, plays[i]));
            bestGenreTemp[genres[i]] += plays[i];
            // bestAlbumTemp.find(genres[i])->second.push_back(make_pair(i, plays[i]));
            // bestGenreTemp.find(genres[i])->second += plays[i];
        }
    }

    vector<pair<string, int>> bestGenreVectorTemp(bestGenreTemp.begin(), bestGenreTemp.end());
    sort(bestGenreVectorTemp.begin(), bestGenreVectorTemp.end(), 
    [](pair<string, int> a, pair<string, int> b){return a.second > b.second;}
    );

    for(int i = 0; i < bestGenreVectorTemp.size(); ++i){
        string currentGenreName = bestGenreVectorTemp[i].first;
        int cnt = 0;

        while(!(bestAlbumTemp[currentGenreName].empty()) && cnt < 2){
            pair<int,int> val = bestAlbumTemp[currentGenreName].top();
            answer.push_back(val.first);
            bestAlbumTemp[currentGenreName].pop();
            ++cnt;
        }
    }



    return answer;
}