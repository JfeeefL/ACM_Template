#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T> class input {
	protected:
		vector<T> data;
		function<T(void)> each_element;
		void read() {
			scanf("%d", &size);
			data.resize(size);
			for(int i = 0; i < size; i ++) {
				data[i] = each_element();
			}
		}
	public:
		int size;
		input() {}
		input(function<T(void)> f): each_element(f) {
			read();
		}
		T& operator [] (int id) {
			return data[id];
		}
		void sort() {
			std::sort(data.begin(),data.end());
		}
		void sort(function<bool(T,T)> f) {
			std::sort(data.begin(),data.end(),f);
		}
};

inline int single_int() {
	int x;
	scanf("%d", &x);
	return x;
}

inline pair<int,int> pair_int() {
	pair<int,int> x;
	scanf("%d%d", &x.first, &x.second);
	return x;
}

int main() {
	input<int> a(single_int);
//	input<pair<int,int> > q(pair_int);
	a.sort([](int a,int b)->bool{return a>b;});
	for(int i = 0; i < a.size; i ++) {
		printf("%d\n", a[i]);
	}
	//
//	q.sort();
	return 0;
}