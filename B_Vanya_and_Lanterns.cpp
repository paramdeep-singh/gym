#include<bits/stdc++.h>

using namespace std;

double getMaxCoverageRequired(vector<int> &lanternPosition, int streetLength) {
	int totalLanterns = lanternPosition.size();
	double maxCoverageRequired = lanternPosition[0] - 0;
	for (int i = 1; i < totalLanterns; i ++) {
		maxCoverageRequired = max(maxCoverageRequired, 
			(lanternPosition[i] - lanternPosition[i - 1]) / 2.0);
	}
	maxCoverageRequired = max(maxCoverageRequired, 
		(double) streetLength - lanternPosition[totalLanterns - 1]);
	return maxCoverageRequired;
}

int main() {
	int totalLanterns, streetLength;
	scanf("%d %d", &totalLanterns, &streetLength);	

	vector<int> lanternPosition(totalLanterns);
	for (int i = 0; i < totalLanterns; i ++) {
		scanf("%d", &lanternPosition[i]);
	}
	sort(lanternPosition.begin(), lanternPosition.end());

	double maxCoverageRequired = getMaxCoverageRequired(
		lanternPosition, 
		streetLength
	);

	printf("%.*f", 10, maxCoverageRequired);

	return 0;	
}