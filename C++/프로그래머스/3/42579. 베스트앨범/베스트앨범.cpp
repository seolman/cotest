#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
  unordered_map<string, int> genre_plays;
  unordered_map<string, vector<pair<int, int>>> songs_by_genre;
  for (int i = 0; i < genres.size(); i++) {
    genre_plays[genres[i]] += plays[i];
    songs_by_genre[genres[i]].push_back({plays[i], i});
  }

  vector<pair<int, string>> sorted_genre;
  for (const auto &[genre, plays] : genre_plays) {
    sorted_genre.push_back({plays, genre});
  }
  sort(sorted_genre.begin(), sorted_genre.end(),
       [](pair<int, string> &a, pair<int, string> &b) {
         return a.first > b.first;
       });

  for (const auto &[plays, genre] : sorted_genre) {
    // cout << "genre: " << genre << endl;
    auto &songs = songs_by_genre[genre];
    sort(songs.begin(), songs.end(), [](pair<int, int> &a, pair<int, int> &b) {
      if (a.first != b.first) {
        return a.first > b.first;
      }
      return a.second < b.second;
    });

    // for (const auto &s : songs) {
    //   cout << "plays: " << s.first << ", " << "idx: " << s.second << endl;
    // }
    for (int i = 0; i < 2 && i < songs.size(); i++) {
      answer.push_back(songs[i].second);
    }
  }
  return answer;
}
