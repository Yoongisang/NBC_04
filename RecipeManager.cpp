#include "RecipeManager.h"
#include <iostream>

PotionRecipe* RecipeManager::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    // 이부분 자세하게 정리 필요함
    for (const auto& r : recipes)
    {
        if (r.GetName() == name)
        {
            return nullptr;
        }
    }
    recipes.emplace_back(name, ingredients);
    return &recipes.back();
}

PotionRecipe* RecipeManager::findRecipeByName(const std::string& name)
{
    
    for (auto& r : recipes)
    {
        if (r.GetName() == name)
        {
            return &r;
        }
    }
    return nullptr;
}

std::vector<PotionRecipe> RecipeManager::findRecipeByIngredient(const std::string& ingredient)
{
    std::vector<PotionRecipe> temp;
    for (const auto& r : recipes)
    {
        for (const auto& i : r.GetIngredients())
        {
            if (i == ingredient)
            {
                temp.push_back(r);
                break;
            }
        }
    }
    return temp;
}


