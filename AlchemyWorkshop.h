#pragma once
#include <vector>
#include <string>
#include "PotionRecipe.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    // 레시피 포션이름 검색
    PotionRecipe searchRecipeByName(std::string name);
    // 재료로 레시피 검색
    std::vector<PotionRecipe> searchRecipeByIngredient(std::string ingredient);
};
