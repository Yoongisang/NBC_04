#pragma once
#include <vector>
#include <string>
#include "PotionRecipe.h"
#include "RecipeManager.h"
#include "StockManager.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
private:
    RecipeManager recipeManager_;
    StockManager stockManager_;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    // 재고 조회 (이름)
    int GetStockByName(const std::string& potionName) const;

    // potionName으로 검색해서 재고 있으면 지급 처리 및 true반환 아니면 fasle 반환
    bool DispensePotionByName(const std::string& potionName);

    // 해당 재료를 포함하는 레시피 중 재고가 있다면 지급처리
    // 실제로 지급되면 물약 이름 목록 반환(없으면 빈벡터)
    std::vector<std::string> DispensePotionByIngredient(const std::string& ingredient);

    // potionName에 공병을 반환처리(최대 3개)
    void ReturnPotionByName(const std::string& potionName);
};
