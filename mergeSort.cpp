#include <bits/stdc++.h>

using namespace std;

int n, x, i;
vector<int> v;

void merge_sort(int l, int r)
{
	if(l == r-1) 
		return;

	int mid = (l+r)/2;

	merge_sort(l, mid);
	merge_sort(mid, r);

	int pos1 = l, pos2 = mid;
	vector<int> aux(r-l);

	for(int i = l, pos = 0; i < r; i++, pos++)
	{
		if(pos1 == mid)
			aux[pos] = v[pos2++];
		else if(pos2 == r)
			aux[pos] = v[pos1++];
		else if(v[pos1]<v[pos2])
			aux[pos] = v[pos1++];
		else
			aux[pos] = v[pos2++];
	}

	for(int i = l, pos = 0; i < r; i++, pos++)
		v[i] = aux[pos];

}

int main()
{
	scanf("%d", &n);

	while(i++ < n)
	{
		scanf("%d", &x);
		v.push_back(x);
	}

	merge_sort(0, n);

	for(auto it:v) 
		printf("%d ", it);

}
