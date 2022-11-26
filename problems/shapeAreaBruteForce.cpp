int solution(int n) {
	//create variable x to hold current area
	//loop till n is reached
	//at every iteration add the new area to the old area
	//calculate new area with equation [ (n-1) * 4];

	int currentArea = 1;
	for (int i = 1; i <= n; i++) {
		currentArea = currentArea + ((i - 1) * 4);
		//cout << currentArea << endl;
		if (i == n) {
			break;
		}
	}
	return currentArea;
}
