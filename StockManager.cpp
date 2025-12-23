#include "StockManager.h"
#include <iostream>

void StockManager::InitializeStock(const std::string& potionName)
{
	// 키값에 포션이름 value값에 3개 입력
	potionStock[potionName] = 3;
}

bool StockManager::DispensePotion(const std::string& potionName)
{
	// 포션 재고가 있다면
	if (potionStock[potionName] > 0)
	{
		// 포션갯수 차감 및 true 반환
		potionStock[potionName]--;
		return true;
	}
	// 없다면 false 반환
	return false;
}

void StockManager::ReturnPotion(const std::string& potionName)
{
	// 포션 갯수가 이미 3개면 재고가 최대임을 출력 및 return
	if (potionStock[potionName] >= MAX_STOCK)
	{
		std::cout << potionName << "재고가 이미 최대입니다. "<< std::endl;
		return;
	}
	// 아니라면 포션 갯수 추가 및 1개 반환되었다는 문구와 남은 재고 출력
	else
	{
		potionStock[potionName]++;
		std::cout << potionName << " 1개 반환 남은 재고: " << potionStock[potionName] << std::endl;
	}
}

int StockManager::GetStock(const std::string& potionName) const
{
	// potionStock의 키값 중 입력된 포션이름과 같은것이있는지 체크
	auto it = potionStock.find(potionName);
	// 찾지못했다면 -1 반환
	if (it == potionStock.end())
	{
		return -1;
	}
	// 아니라면 갯수 반환
	return it->second;
}


