/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image 
starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the 
starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those 
pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.
*/
#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define vi vector<int>
int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};

void dfs(vvi &image, int &m, int &n, int i, int j, int &color, int &newColor){
	if(i >= m || j >= n || i < 0 || j < 0 || image[i][j] != color){
		return;
	}

	image[i][j] = newColor;

	for(int k = 0; k < 4; k++){
		int r = i + x[k];
		int c = j + y[k];

		dfs(image, m, n, r, c, color, newColor);
	}
}

vvi floodFill(vvi &image, int m, int n, int sr, int sc, int newColor){
	int color = image[sr][sc];

	// color == newColor we don't need to do the flood fill
	if(color != newColor) dfs(image, m, n, sr, sc, color, newColor);

	return image;
}

int main(){
	int m, n;
	cin >> m >> n;
	vvi image(m, vi(n));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> image[i][j];
		}
	}

	int sr, sc, newColor;
	cout << "Enter source: ";
	cin >> sr >> sc;
	cout << "Enter New Color: ";
	cin >> newColor;

	vvi res = floodFill(image, m, n, sr, sc, newColor);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}