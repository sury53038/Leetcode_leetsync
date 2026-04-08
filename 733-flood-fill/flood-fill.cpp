class Solution {
public:
    vector<int>dr{0,0,-1,1};
    vector<int>dc{-1,1,0,0};

    void dfs(vector<vector<int>>& img, int sr, int sc, int &colour, int &value){
        if(sr < 0 || sr >= img.size() || sc < 0 || sc >= img[0].size()) return;
        
        else if(img[sr][sc] == value){
            img[sr][sc] = colour;
            for(int i = 0; i < 4; i++){
                int ii = dr[i] + sr;
                int jj = dc[i] + sc;
                dfs(img, ii, jj, colour, value);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int value = image[sr][sc];

        if(value == color) return image;
        dfs(image, sr, sc, color, value);
        return image;
    }
};