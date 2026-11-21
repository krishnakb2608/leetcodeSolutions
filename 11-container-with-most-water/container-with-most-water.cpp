class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j= height.size()-1;
        int area=0;
        int max_area=0;
        while(i<=j){
            area=min(height[i],height[j])*(j-i);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
            max_area=max(max_area,area);
        }
        return max_area;
    

    }
};