#include <iostream>
class DumbBell {
private:
	int weight;
public:
	void setWeight(int w)
	{
		weight = w;
	}
	int getWeight() {
		return weight;
	}
};
int main()
{
	DumbBell bar;
	bar.setWeight(200);
	std::cout << "The weight is " << bar.getWeight() << "\n";
	return 0;
}