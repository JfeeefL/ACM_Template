#include <vector>

typedef unsigned long long int size_type;

template <typename T> class BIT_BASE {
	private: 
		std::vector<T> s;
		inline size_type lowbit(size_type t) {
			return t&(-t);
		}
	protected: 
	virtual T query(size_type p) {
		T ans = 0;
		while(p < s.size()) {
			ans += s[p];
			p += lowbit(p);
		}
		return ans;
	}
	virtual void add(size_type p, T a) {
		while(p) {
			s[p] += a;;
			p ^= lowbit(p);
		}
	}
	public:
		BIT_BASE () {}
		void resize(size_type n) {
			s.resize(n+1,0);
		}
		BIT_BASE(size_type n): s(n) {
			resize(n);
		}
};

template<typename T> class BIT: public BIT_BASE<T> {
	public:
	BIT() {}
	BIT(size_type size) {
		BIT_BASE<T>::resize(size);
	}
	T query(size_type position) {
		return BIT_BASE<T>::query(position);
	}
	void modify(size_type position, T value) {
		BIT_BASE<T>::add(position, value);
	}
};

int main() {
	BIT<int> t(10);
	return 0;
}
