#include<bits/stdc++.h>

using namespace std;

const int N = 1009;
int lanternPosition[N];

int main() {
	int totalLanterns, streetLength;
	scanf("%d %d", &totalLanterns, &streetLength);	

	for (int i = 0; i < totalLanterns; i ++) {
		scanf("%d", &lanternPosition[i]);
	}

	sort(lanternPosition, lanternPosition + totalLanterns);

	double maxCoverageRequired = lanternPosition[0] - 0;
	for (int i = 1; i < totalLanterns; i ++) {
		maxCoverageRequired = max(maxCoverageRequired, 
			(lanternPosition[i] - lanternPosition[i - 1]) / 2.0);
	}
	maxCoverageRequired = max(maxCoverageRequired, 
		(double) streetLength - lanternPosition[totalLanterns - 1]);


	printf("%.*f", 10, maxCoverageRequired);

	return 0;	
}