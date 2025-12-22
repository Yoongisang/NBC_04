#pragma once
#include <map>
#include <string>

class StockManager
{
private:
	std::map<std::string, int> potionStock;
	const int MAX_STOCK = 3;
	
public:
	void InitializeStock(const std::string& potionName);
	bool DispensePotion(const std::string& potionName);
	void ReturnPotion(const std::string& potionName);
	int GetStock(const std::string& potionName) const { return potionStock.at(potionName); }
};

