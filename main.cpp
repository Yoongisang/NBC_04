#include <iostream>
#include <vector>
#include <string>
#include "AlchemyWorkshop.h"



int main() {
    AlchemyWorkshop myWorkshop; 

    while (true) {
        // 메뉴 화면
        std::cout << "*연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 물약 재고 조회(이름)" << std::endl;
        std::cout << "4. 물약이름으로 물약 지급" << std::endl;
        std::cout << "5. 재료가 포함된 물약 지급" << std::endl;
        std::cout << "6. 공병 반환" << std::endl;
        std::cout << "7. 종료" << std::endl;
        std::cout << "선택: ";
        // 입력
        int choice;
        std::cin >> choice;
        // 잘못된 입력 체크
        if (std::cin.fail()) {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        // 제대로된 입력들
        if (choice == 1) {
            // 포션 추가
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true) {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2) {
            // 2번 모든 레시피 출력
            myWorkshop.displayAllRecipes();
        }
        else if (choice == 3) {
            // 재고 조회(이름)
            std::cout << "물약 이름 입력: ";
            std::string potionName;
            std::cin >> potionName;
            int stock = myWorkshop.GetStockByName(potionName);
            // AlchemyWorkshop의 GetStockByName()함수 -> StockManager의 GetStock()함수로 GeStock()함수에서 물약이름으로 찾지 못했다면 -1 반환
            // -1 반환된다면 물약이 존재하지 않습니다 출력
            if (stock == -1)
            {
                std::cout << "물약이 존재하지 않습니다." << std::endl;
            }
            else
            {
                // 재고가 있다면 남은 재고 출력
                std::cout << "남은 물약 재고: " << stock << "개" << std::endl;
            }
           
        }
        else if (choice == 4) {
            // 물약 이름으로 지급
            std::cout << "물약 이름 입력: ";
            std::string potionName;
            std::cin >> potionName;
            if (myWorkshop.DispensePotionByName(potionName) == true)
            {
                std::cout << potionName << " 1개 지급완료, 남은 물약 재고: " << myWorkshop.GetStockByName(potionName) << std::endl;
            }
            else
            {
                std::cout << "찾을 수 없습니다." << std::endl;
            }
        }
        else if (choice == 5)
        {
            // 재료 기준으로 지급
            std::cout << "재료 입력: ";
            std::string ingredient;
            std::cin >> ingredient;
            // 재료로 검색한 벡터를 반환
            // 여기서 아무것도 못찾는다면 빈 벡터 반환 찾는다면 재료이름 벡터 반환과 재고 지급 
            auto potionNames = myWorkshop.DispensePotionByIngredient(ingredient);
            std::cout << "*지급된 물약 리스트" << std::endl;
            // false 값이 반환된다면 찾을 수 없습니다. 출력
            if (potionNames.empty())
            {
                std::cout << "찾을 수 없습니다." << std::endl;
            }
            // true값이 반환된다면 한줄씩 출력
            for (const auto& i : potionNames)
            {
                std::cout << i << " 1개 지급완료 남은 재고: " << myWorkshop.GetStockByName(i) << std::endl;
            }

        }
        else if (choice == 6)
        {
            // 공병 반환
            std::cout << "반환할 물약 공병 이름 입력: ";
            std::string potionName;
            std::cin >> potionName;
            // RecipeManager의 findRecipeByName로 예외사항 체크 반환이 된다면 StockManager의 ReturnPotion로 반환
            myWorkshop.ReturnPotionByName(potionName);
            
        }
        else if (choice == 7)
        {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            break;
        }
        else {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }
    }

    return 0;
}