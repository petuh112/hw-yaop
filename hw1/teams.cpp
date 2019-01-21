#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// *You* are not allowed to use global variables
//  but for just the output portion *we* will. ;>
int combo = 1;

// @brief Prints a single combination of teams
//
// @param[in] team1 Array containing the names of team 1
// @param[in] team2 Array containing the names of team 2
// @param[in] len Size of each array
void printSolution(const string* team1, 
		   const string* team2,
		   int len)
{
  cout << "\nCombination " << combo++ << endl;
  cout << "T1: ";
  for(int i=0; i < len; i++){
    cout << team1[i] << " ";
  }
  cout << endl;
  cout << "T2: ";
  for(int i=0; i < len; i++){
    cout << team2[i] << " ";
  }
  cout << endl;
}

// You may add additional functions here
void recurse(string* ppl, string* team1, 
		   string* team2,
		   int index, int left, int len, int t1, int t2){
  if(left == 0){
    for(int i = index;i < len;i++){
      team2[t2] = ppl[i];
      t2++;
    }
    printSolution(team1, team2, len/2);
    return;
  }
  else if(len == left + index){
    for(int i = index;i < len;i++){
      team1[t1] = ppl[i];
      t1++;
    }
    printSolution(team1, team2, len/2);
    return;
  }
  team1[t1] = ppl[index];
  recurse(ppl, team1, team2, index + 1, left - 1,len, t1 + 1, t2);
  team1[t1] = "";
  team2[t2] = ppl[index];
  recurse(ppl, team1, team2, index + 1, left,len, t1, t2+1);
}



int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide a file of names" << endl;
    return 1;
  }
  // Complete the rest of main
  ifstream ifile(argv[1]);
  if (ifile.fail()){
    cout << "Error" << endl;
    return 1;
  }
  int num;
  ifile >> num;
  string* ppl = new string[num];
  string* team1 = new string[num/2];
  string* team2 = new string[num/2];
  for(int i = 0;i < (num/2);i++){
    team1[i] = "";
    team2[i] = "";
  }
  for(int i = 0; i < num; i++){
    ifile >> ppl[i];
  }
  recurse(ppl, team1, team2, 0, num/2, num, 0, 0);


  return 0;
}
