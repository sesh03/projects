#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

#define MAX_TEAMS 26
using namespace std;


void process_race_outcome(string outcome) {
   int num_teams = 0; //number of teams
   int total_runners = outcome.length(); //total runners in the race
   int runners_per_team = 0; //number of runner per team
   char teams[MAX_TEAMS]; //teams in the race

   //extracting teams
   string temp_outcome = outcome;
   sort(temp_outcome.begin(), temp_outcome.end()); //sorts the temp_outcome
   string::iterator it;
   it = unique(temp_outcome.begin(), temp_outcome.end());
   for (string::iterator i = temp_outcome.begin(); i != it; ++i) {
       teams[num_teams] = *i;
       num_teams++;
   }
   int team_runner_count[num_teams];
   int team_scores[num_teams];

   //extracting runners' count and their scores
   for (int i = 0; i < num_teams; i++) {
       team_runner_count[i] = 0;
       team_scores[i] = 0;
       char team = teams[i];
       for (int j = 0; j < total_runners; j++) {
           if (team == outcome.at(j)) {
               team_runner_count[i]++;
               team_scores[i] += (j + 1);
           }
       }
   }

   //checking if each team has same number of runners
   for (int i = 0; i < num_teams - 1; i++) {
       if (team_runner_count[i] == team_runner_count[i + 1])
           continue;
       else {
           cerr << endl << "Teams dont't have same number of runners." << endl;
           cerr << "Ignoring..." << endl;
           return;
       }
   }
   runners_per_team = team_runner_count[0];

   
   cout << "There are " << num_teams << " teams." << endl;
   cout << "Each team has " << runners_per_team << " runners." << endl;

   cout << "Team" << setw(7) << "Score" << endl;
   cout << "----" << setw(5) << "----" << endl;
   float winner_score = 0.0;
   char winner_team;
   for (int i = 0; i < num_teams; i++) {
       float score = team_scores[i] / runners_per_team;
       cout << teams[i] << setw(7) << score << endl;
   }

   //checking for winner team
   winner_score = team_scores[0] / runners_per_team;
   winner_team = teams[0];
   for (int i = 1; i < num_teams; i++) {
       float score = team_scores[i] / runners_per_team;
       if (score < winner_score) {
           winner_score = score;
           winner_team = teams[i];
       }
   }
   cout << "The winning team is " << winner_team << " with a score of "
           << winner_score << endl;

}

//main() function
int main() {
   string race_outcome;
   while (true) {
       fflush(stdin);
       cout << "Enter race outcome:";
       getline(cin, race_outcome);
       if (race_outcome.compare("done") == 0) {
           cout << "Exiting..." << endl;
           exit(1);
       }
       process_race_outcome(race_outcome);
   }
   return 0;
}

