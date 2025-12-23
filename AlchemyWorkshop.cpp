#include "AlchemyWorkshop.h"
#include <iostream>
#include <algorithm>


void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    // RecipeManager 클래스의 addRecipe()함수로 포인터를 반환해 nullptr이면 레시피 추가 실패출력 후 return
    auto* temp = recipeManager_.addRecipe(name, ingredients);
    if (temp == nullptr)
    {
        std::cout << "레시피 추가에 실패했습니다." << std::endl;
        return;
    }
    // nullptr이 아니라면 첫 레시피 추가할때 stockManager의 첫 입력 stock 초기화 후 레시피 추가 완료 출력
    stockManager_.InitializeStock(name);
	std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
}

void AlchemyWorkshop::displayAllRecipes() const
{
    // RecipeManager 클래스의 getAllRecipe로 vector<PotionRecipe> recipes를 diplayRecipem에 반환 
    auto displayRecipes = recipeManager_.getAllRecipes();
    // 빈 벡터가 반환되었다면 아직 등록된 레시피가 없는걸로 출력 후 return
    if (displayRecipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }
    // 빈 벡터가 아니라면 전체 레시피 출력
    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (const auto& it : displayRecipes)
    {
        std::cout << "- 물약 이름: " << it.GetName() << std::endl;
        std::cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        bool first = true;
        for (auto Ingr : it.GetIngredients()) 
        {
            // 첫 재료가 아니면 앞에 쉼표 추가
            if (first != true)
            {
                std::cout << ", ";
            }
            std::cout << Ingr;
            first = false;
        }
        std::cout << std::endl;
        std::cout << "  > 재고: " << stockManager_.GetStock(it.GetName()) << std::endl;
    }
    std::cout << "---------------------------\n";
}

int AlchemyWorkshop::GetStockByName(const std::string& potionName) const
{
    // StockManager클래스의 GetStock으로 남은 재고 반환 예외사항 처리는 StockManager 클래스에서 해결
    return stockManager_.GetStock(potionName);
}

bool AlchemyWorkshop::DispensePotionByName(const std::string& potionName)
{
    // 포션 이름으로 찾아 지급하기 위해 입력된 포션이 있는지 RecipeManager클래스의 findRecipeByName으로 체크
    // 존재하지 않는다면 nullptr을 반환하기 때문에 false를 return 해준다.
    if (recipeManager_.findRecipeByName(potionName) == nullptr)
    {
        return false;
    }
    // 포션레시피가 있고 재고가 있다면 StockManager의 DispensPotion으로 재고를 -1 하고 true 출력
    return stockManager_.DispensePotion(potionName);
}

std::vector<std::string> AlchemyWorkshop::DispensePotionByIngredient(const std::string& ingredient)
{
    // 반환하기 위한 벡터 생성
    std::vector<std::string> PotionList;
    // RecipeManager 클래스의 findRecipeByIngredient로 재료가 포함된 레시피 벡터를 반환
    auto recipe = recipeManager_.findRecipeByIngredient(ingredient);
    // 반환된 벡터를 순환하면서 벡터의 GetName으로 포션이름을 DispensePotion()함수에 입력
    // 반환값이 true라면 재고가 0 초과라서 지급이 되기때문에 PotionList 벡터에 포션 이름을 입력
    for (const auto& r : recipe)
    {
        if (stockManager_.DispensePotion(r.GetName()))
        {
            PotionList.push_back(r.GetName());
        }
    }
    // 찾은 포션들을 입력한 벡터 반환
    return PotionList;
}

void AlchemyWorkshop::ReturnPotionByName(const std::string& potionName)
{
    // 포션이름으로 찾은 포인터 반환값이 nullptr이라면 존재하지 않습니다. 출력 후 return
    if (recipeManager_.findRecipeByName(potionName) == nullptr)
    {
        std::cout << potionName << "은 존재하지 않습니다." << std::endl;
        return;
    }
    // 아니라면 포션 반환
    stockManager_.ReturnPotion(potionName);

}
