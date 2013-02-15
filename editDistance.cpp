ass Solution {
    public :int minDistance(string word1, string word2) {
        // Start typing your Java solution below
        // DO NOT write main() function
    
        int dis[1000][1000];
    	for (int i=0;i<=word1.size();i++)
		for (int j=0;j<=word2.size();j++) {
			dis[i][j] = ~(1<<31);
		}
		for (int i=0;i<=word2.size();i++) {
			dis[0][i] = i;
		}
		for (int i=0;i<=word1.size();i++) {
			dis[i][0] = i;
		}
		for (int i=1; i<=word1.size();i++)
		 for (int j=1; j<=word2.size();j++) {
			dis[i][j] = min(dis[i][j], dis[i-1][j] + 1);
			dis[i][j] = min(dis[i][j], dis[i][j-1] + 1);
			if (word1[i-1]==word2[j-1]) {
				dis[i][j] = min(dis[i][j],dis[i-1][j-1]);
			} else {
				dis[i][j] = min(dis[i][j], dis[i-1][j-1] +1);
			}
			
		}
        return dis[word1.size()][word2.size()];
    }
};
