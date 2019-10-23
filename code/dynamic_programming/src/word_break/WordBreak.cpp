// A program that checks whether it is possible to break a string into multiple
// contiguous substrings such that each of the substring is present in the 
// dictonary of allowed strings


#include <bits/stdc++.h> 
using namespace std; 

bool wordBreak(string s,string dict[],int dict_size){ 
	int i,j,k,n=(int)s.size(); 
	if (n==0) return true;
	bool dp[n+1];
	memset(dp,false,sizeof(dp));
	vector<int> ind; 
	ind.push_back(-1); 
	for(i=0;i<n;i++){ 
		bool flag=false;
		for(j=(int)ind.size()-1;j>=0;j--){ 
			string temp =s.substr(ind[j]+1,i-ind[j]); 
            for(k=0;k<dict_size;k++){
                if(dict[k]==temp){
                    flag=true;
                    break;
                }
            }
		}
		if(flag){ 
			dp[i]=true; 
			ind.push_back(i); 
		} 
	} 
	return dp[n-1]; 
} 

int main(){ 
    int i,n;
    cout<<"Enter the size of dictionaries :";
    cin>>n;
    string dict[n];
    for(i=0;i<n;i++) cin>>dict[i];
    string word;
    cout<<"Enter the word : ";
    cin>>word;
	wordBreak(word,dict,n) ? cout<<"Yes":cout<<"No";
	return 0; 
} 