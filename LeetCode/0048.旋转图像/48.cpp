#include <vector>

void rotate(vector<vector<int>>& matrix){
    int n = matrix.size();

    //对角线交换
    for(int i =0; i < n; ++i){
        for(int j = i; j < n; ++j){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //每一行反转
    for(int i =0; i < n; ++i){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

//解旋转90度后，每个元素的新位置与原位置的关系。在这个问题中，原矩阵的第i行变成了旋转后矩阵的第n - i列，这就是为什么要先做对角线交换，然后再对每行进行翻转的原因。