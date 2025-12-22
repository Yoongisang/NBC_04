#include "StockManager.h"
#include <iostream>

void StockManager::InitializeStock(const std::string& potionName)
{
	potionStock[potionName] = 3;
}

bool StockManager::DispensePotion(const std::string& potionName)
{
	if (potionStock[potionName] > 0)
	{
		potionStock[potionName]--;
		return true;
	}
	return false;
}

void StockManager::ReturnPotion(const std::string& potionName)
{
	if (potionStock[potionName] >= MAX_STOCK)
	{
		std::cout << potionName << "재고가 이미 최대입니다. "<< std::endl;
		return;
	}
	else
	{
		potionStock[potionName]++;
		std::cout << potionName << " 1개 반환 남은 재고: " << potionStock[potionName] << std::endl;
	}
}


