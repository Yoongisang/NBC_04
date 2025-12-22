#include "AlchemyWorkshop.h"
#include <iostream>
#include <algorithm>


void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    auto* temp = recipeManager_.addRecipe(name, ingredients);
    if (temp == nullptr)
    {
        std::cout << "레시피 추가에 실패했습니다." << std::endl;
        return;
    }
    stockManager_.InitializeStock(name);
	std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
}

void AlchemyWorkshop::displayAllRecipes() const
{
    auto displayRecipes = recipeManager_.getAllRecipes();
    if (displayRecipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (int i = 0; i < displayRecipes.size(); ++i) {
        std::cout << "- 물약 이름: " << displayRecipes[i].GetName() << std::endl;
        std::cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        bool first = true;
        for (auto Ingr : displayRecipes[i].GetIngredients()) {
            // 첫 재료가 아니면 앞에 쉼표 추가
            if (first != true)
            {
                std::cout << ", ";
            }
            std::cout << Ingr;
            first = false;
        }
        std::cout << std::endl;
        std::cout << "  > 재고: " << stockManager_.GetStock(displayRecipes[i].GetName()) << std::endl;
    }
    std::cout << "---------------------------\n";
}

int AlchemyWorkshop::GetStockByName(const std::string& potionName) const
{
    return stockManager_.GetStock(potionName);
}

bool AlchemyWorkshop::DispensePotionByName(const std::string& potionName)
{
     
    if (recipeManager_.findRecipeByName(potionName) == nullptr)
    {
        return false;
    }
    return stockManager_.DispensePotion(potionName);
}

std::vector<std::string> AlchemyWorkshop::DispensePotionByIngredient(const std::string& ingredient)
{
    std::vector<std::string> PotionList;
    auto recipe = recipeManager_.findRecipeByIngredient(ingredient);
    
    for (const auto& r : recipe)
    {
        if (stockManager_.DispensePotion(r.GetName()))
        {
            PotionList.push_back(r.GetName());
        }
    }
    return PotionList;
}

void AlchemyWorkshop::ReturnPotionByName(const std::string& potionName)
{
    if (recipeManager_.findRecipeByName(potionName) == nullptr)
    {
        std::cout << potionName << "은 존재하지 않습니다." << std::endl;
        return;
    }

    stockManager_.ReturnPotion(potionName);

}
