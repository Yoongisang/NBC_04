#pragma once
#include "PotionRecipe.h"

class RecipeManager
{
private:
	// 포션 레시피 클래스 자료형을 가진 벡터 
	std::vector<PotionRecipe> recipes;

public:
	// 포션을 추가하고 포인터로 반환 -> AlchemyWorkshop에서 사용할때 nullptr 체크로 예외사항 처리를 하기 위해
	PotionRecipe* addRecipe(const std::string& name, const std::vector<std::string>& ingredients);
	// 포션을 찾고 포인터로 반환 -> AlchemyWorkshop에서 사용할때 nullptr 체크로 예외사항 처리를 하기 위해
	PotionRecipe* findRecipeByName(const std::string& name);
	// 재료로 검색된 레시피들을 벡터로 반환
	std::vector<PotionRecipe> findRecipeByIngredient(const std::string& ingredient);
	// 모든 레시피를 반환
	const std::vector<PotionRecipe>& getAllRecipes() const { return recipes; }
};

