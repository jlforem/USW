struct ThreeVals
{
	int a, b, c;
	void ThreeVals()
	{
		a = 1; b = 2; c = 3;
	}
};

int main()
{
	ThreeVals vals;
	cout << vals << endl;
	return 0;
}