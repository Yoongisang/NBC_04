#pragma once
#include <string>
#include <vector>

// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
class PotionRecipe {
private:
    // 포션이름
    std::string potionName;
    //포션재료 벡터
    std::vector<std::string> ingredients; // 단일 재료에서 재료 '목록'으로 변경
public:
    // 생성자: 재료 목록을 받아 초기화하도록 수정
    PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
        : potionName(name), ingredients(ingredients) {
    }
    // 포션이름 반환
    const std::string& GetName() const { return potionName; }
    // 포션재료 반환
    const std::vector<std::string>& GetIngredients() const { return ingredients; }
};