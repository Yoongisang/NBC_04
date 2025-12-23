#pragma once
#include <map>
#include <string>

class StockManager
{
private:
	// 키값 == 포션이름, value값 == 재고
	std::map<std::string, int> potionStock;
	// 포션 최대갯수
	const int MAX_STOCK = 3;
public:
	// 포션 초기화
	void InitializeStock(const std::string& potionName);
	// 포션 지급
	bool DispensePotion(const std::string& potionName);
	// 포션 회수
	void ReturnPotion(const std::string& potionName);
	// 포션 재고 반환
	int GetStock(const std::string& potionName) const;
};

