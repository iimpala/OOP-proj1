//RecipeDB
#include "RecipeDatabase.h"
#include <vector>
#include <string>
#include <algorithm>

RecipeDatabase::RecipeDatabase(){
    std::vector< std::vector<std::string> > data;
    file_manager = FileManager();
    data = file_manager.load();

    int i = 0;
    for(auto recipe = data.begin(); recipe != data.end(); recipe){
        recipe_list.push_back(Recipe());
    }
}

void RecipeDatabase::showAllRecipes(){
    for(int i = 0; i < recipe_list.size(); i++){
        std::cout<<to_string(i)<<". "<<recipe_list[i].getRecipeName()<<std::endl;
    }
}

void RecipeDatabase::insertRecipe(Recipe recipe){
    recipe_list.push_back(recipe);
}

void RecipeDatabase::deleteRecipe(Recipe recipe){
    for(int i = 0; i < recipe_list.size(); i++){
        if(isEqual(recipe_list[i],recipe)){
            recipe_list.erase(recipe_list.begin() + i);
        }
    }
} 

void RecipeDatabase::updateRecipe(Recipe recipe){
    for(Recipe existingRecipe : recipe_list){
        if(isEqual(existingRecipe,recipe)){
            existingRecipe.setRecipeName(recipe.getRecipeName());
            existingRecipe.setTime(recipe.getTime());
            existingRecipe.setIngredients(recipe.getIngredients());
            existingRecipe.setCookingOrder(recipe.getCookingOrder());
        }
    }
}

std::vector<Recipe> RecipeDatabase::getRecipes(){
    return recipe_list;
}

std::vector<Recipe> RecipeDatabase::searchRecipesByIngredient(std::string ingredient){
    std::vector<Recipe> searched_list;

    for(Recipe existingRecipe : recipe_list){
        if(hasIngredient(existingRecipe, ingredient)){
            searched_list.push_back(existingRecipe);
        }
    }

    return searched_list;
}

std::vector<Recipe> RecipeDatabase::searchRecipesByRecipeName(std::string recipename){
    std::vector<Recipe> searched_list;

    for(Recipe existingRecipe : recipe_list){
        if(isSameName(existingRecipe, recipename)){
            searched_list.push_back(existingRecipe);
        }
    }
 
    return searched_list;
}

bool isSameName(Recipe existingRecipe, std::string recipename){
    if(existingRecipe.getRecipeName().compare(recipename)) return true;
    else return false;
}

bool hasIngredient(Recipe existingRecipe, std::string ingredient){
    for(Ingredient ingredients : existingRecipe.getIngredients()){
        if(ingredients.getName().compare(ingredient)) return true;
    }
    return false;
}

bool isEqual(Recipe r1, Recipe r2){
    return true;
    // if(r1.getId() == r2.getId())
    //     return true;
    // else
    //     return false;
}