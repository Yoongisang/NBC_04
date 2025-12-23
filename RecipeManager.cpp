#include "RecipeManager.h"
#include <iostream>

PotionRecipe* RecipeManager::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    // 레시피가 저장된 벡터 순환
    for (const auto& r : recipes)
    {
        // 벡터의 GetName()으로 반환된 포션 이름이 추가하려는 포션의 이름과 같다면 nullptr을 반환
        if (r.GetName() == name)
        {
            return nullptr;
        }
    }
    // 동일한 이름의 포션이 없다면 레시피가 저장된 벡터의 마지막에 추가
    // emplace_back은 공간을 만든다음 생성자를 이용해서 공간이 생기자 마자 입력하는 방식이라 효율 적임
    recipes.emplace_back(name, ingredients);

    return &recipes.back();
}

PotionRecipe* RecipeManager::findRecipeByName(const std::string& name)
{
    // 레시피 벡터를 순환
    for (auto& r : recipes)
    {   // 벡터의 포션 이름이 입력한 포션이름과 같다면 벡터의 주소 반환
        if (r.GetName() == name)
        {
            return &r;
        }
    }
    // 검색했을때 나오지 않는다면 nullptr 반환
    return nullptr;
}

std::vector<PotionRecipe> RecipeManager::findRecipeByIngredient(const std::string& ingredient)
{
    // 임시 포션 레시피 벡터 
    std::vector<PotionRecipe> temp;
    for (const auto& r : recipes)
    {
        // 레시피 벡터의 순환중 벡터의 재료 전체 순환
        for (const auto& i : r.GetIngredients())
        {
            // 벡터에 재료중에 입력된 재료와 같은게 존재하는지 체크
            if (i == ingredient)
            {
                // 존재한다면 포션 레시피 백터에 추가 후 반복문 종료
                temp.push_back(r);
                break;
            }
        }
    }
    // 저장된 포션 레시피 벡터 반환
    return temp;
}


