#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::cin; using std::string; using std::floor; using std::cout; using std::vector; using std::rand; using std::endl;

vector<int> A = {1, 3, 5};
vector<int> B = {2, 4, 6};
vector<int> C;
vector<int> D = {3, 4, 2, 6, 5, 1};
vector<int> exclude_list;

int n = D.size();

// Merge Sort

vector<int> concat(int temp_1, vector<int> temp_2){
	temp_2.insert(temp_2.begin(), temp_1);
	return temp_2;
}

vector<int> merge(vector<int> vec_1, vector<int> vec_2){

  	int temp;

	if(vec_1.empty()){
		return vec_2;
	} else if(vec_2.empty()){
		return vec_1;
	} else if(vec_1[0] < vec_2[0]){
		temp = vec_1[0];
		vec_1.erase(vec_1.begin());
		return concat(temp, merge(vec_1, vec_2));
	} else {
		temp = vec_2[0];
		vec_2.erase(vec_2.begin());	
		return concat(temp, merge(vec_1, vec_2));
	}
}

vector<int> mergeSort(vector<int> vec, int n){

	if(n == 1){return vec;}
	int mid = floor(n / 2);
	vector<int> leftHalf, rightHalf;
	leftHalf.insert(leftHalf.begin(), vec.begin(), vec.begin() + mid);
	rightHalf.insert(rightHalf.begin(), vec.begin() + mid, vec.end());
	return merge(mergeSort(leftHalf, mid), mergeSort(rightHalf, (n - mid))); 	

} 

// Exponential Search

int x = 15;
vector<int> arr_temp = {64, 25, 12, 22, 11};

int exp_search(int x){

        int i, j = 0;

        for(int i; i < arr_temp.size(); i = i + j){

                if(arr_temp[i] == x){
                        return i;
                } else if(arr_temp[i] > x){
                        arr_temp.erase(arr_temp.begin() + i, arr_temp.end());
                        i = j = 0;
                } else {
                        j = i;
                        ++i;
                }
        }
}

// Bubble Sort

void bubble_sort(vector<int> &arr_temp, int change = 0){

	for(int i = 0; i < (arr_temp.size()-1); ++i){
		if(arr_temp[i] > arr_temp[i+1]){
			int temp = arr_temp[i];
			arr_temp[i] = arr_temp[i+1];
			arr_temp[i+1] = temp;			
			++change;
		}
	}

	if(change > 0){bubble_sort(arr_temp, change = 0);}

}

void insertion_sort(vector<int> &arr_temp){

	for(int i = 0; i < arr_temp.size(); ++i){
		for(int j = 0; j < i; ++j){
			if(arr_temp[i] < arr_temp[j]){
				vector<int> temp;
				temp.insert(temp.begin(), arr_temp.begin(), arr_temp.begin() + j);
				temp.push_back(arr_temp[i]);
				arr_temp.erase(arr_temp.begin() + i);
				arr_temp.erase(arr_temp.begin(), arr_temp.begin() + j);
				temp.insert(temp.end(), arr_temp.begin(), arr_temp.end());
				arr_temp = temp;
				temp.clear();
				break;
			}
		}
		
		
	}

}



int main()
{

	vector<int> ex = {6, 4, 5, 2, 3, 1};

	vector<int> temp = mergeSort(ex, ex.size());

	for(int i = 0; i < temp.size(); ++i){
		cout << temp[i] << endl;
	}

}

