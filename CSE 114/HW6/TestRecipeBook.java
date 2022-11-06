/*
 * Daniel Langer
 * 11462901
 */

class Ingredient {
    private String name, measuringUnit;
    private int caloriesPerUnit;

    public Ingredient(String initName, String initMeasuringUnit, int initCaloriesPerUnit) {
        name = initName;
        measuringUnit = initMeasuringUnit;
        caloriesPerUnit = initCaloriesPerUnit;
    }

    public int getCalories() {
        return caloriesPerUnit;
    }

    public String getName() {
        return name;
    }

    public String getMeasuringUnit() {
        return measuringUnit;
    }

    public String toString() {
        return "Ingredient:\n" + " name=" + name + "\n" + " measuringUnit=" + measuringUnit + "\n" + " caloriesPerUnit="
                + caloriesPerUnit;
    }

    public boolean equals(Ingredient ing2) {
        if ((this.getName() == ing2.getName()) && (this.getMeasuringUnit() == ing2.getMeasuringUnit())
                && (this.getCalories() == ing2.getCalories())) {
            return true;
        } else {
            return false;
        }
    }
}

class RecipeIngredient extends Ingredient {
    private float quantity;

    public RecipeIngredient(String initName, String initMeasuringUnit, int initCaloriesPerUnit, float initQuantity) {
        super(initName, initMeasuringUnit, initCaloriesPerUnit);
        quantity = initQuantity;
    }

    public float getQuantity() {
        return quantity;
    }

    public void setQuantity(float newQuantity) {
        quantity = newQuantity;
    }

    public String toString() {
        return "Ingredient:\n" + " name=" + this.getName() + "\n" + " quantity=" + this.getQuantity() + "\n"
                + " measuringUnit=" + this.getMeasuringUnit() + "\n" + " caloriesPerUnit="
                + this.getCalories();
    }

    public boolean equals(RecipeIngredient ing2) {
        if ((this.getName() == ing2.getName()) && (this.getMeasuringUnit() == ing2.getMeasuringUnit())
                && (this.getCalories() == ing2.getCalories()) && (this.getQuantity() == ing2.getQuantity())) {
            return true;
        } else {
            return false;
        }
    }
}

class CookingRecipe {
    private String name;
    RecipeIngredient[] ingredientList = new RecipeIngredient[0];

    public CookingRecipe(String initName) {
        name = initName;
    }

    public String getName() {
        return name;
    }

    /**
     * if the recipe already includes the ingredient specified by the parameter,
     * then just update the quantity, otherwise add a new recipe ingredient.
     */
    public void addOrUpdateRecipeIngredient(Ingredient newIngredient, float newQuantity) {
        RecipeIngredient newRI = new RecipeIngredient(newIngredient.getName(), newIngredient.getMeasuringUnit(),
                newIngredient.getCalories(), newQuantity);
        boolean exists = false;

        for (RecipeIngredient ingredient : ingredientList) {
            if (ingredient.equals(newIngredient)) {
                exists = true;
                ingredient.setQuantity(newQuantity);
            }
        }

        if (!exists) {
            RecipeIngredient[] tempList = new RecipeIngredient[ingredientList.length + 1];
            for (int i = 0; i < ingredientList.length; i++) {
                RecipeIngredient ing2 = ingredientList[i];
                tempList[i] = new RecipeIngredient(ing2.getName(), ing2.getMeasuringUnit(), ing2.getCalories(),
                        ing2.getQuantity());
            }
            tempList[tempList.length - 1] = newRI;
            ingredientList = tempList;
        }
    }

    public RecipeIngredient getRecipeIngredient(Ingredient inputIngredient) {
        for (RecipeIngredient ingredient : ingredientList) {
            if (ingredient.equals(inputIngredient)) {
                return ingredient;
            }
        }
        return null;
    }

    /**
     * returns the RecipeIngredient object corresponding to the ingredient object
     * parameter, or return null if the ingredient is not part of the recipe.
     */
    public RecipeIngredient getRecipeIngredient(String ingredientName) {
        for (RecipeIngredient ingredient : ingredientList) {
            if (ingredient.getName().equals(ingredientName)) {
                return ingredient;
            }
        }
        return null;
    }

    public RecipeIngredient removeRecipeIngredient(Ingredient inputIngredient) {
        for (RecipeIngredient ingredient : ingredientList) {
            if (ingredient.equals(inputIngredient)) {
                RecipeIngredient[] tempArray = new RecipeIngredient[ingredientList.length - 1];
                int tempArrayIndex = 0;
                for (RecipeIngredient ing : ingredientList) {
                    if (!(ing.equals(inputIngredient))) {
                        tempArray[tempArrayIndex] = new RecipeIngredient(ing.getName(), ing.getMeasuringUnit(),
                                ing.getCalories(), ing.getQuantity());
                        tempArrayIndex++;
                    }
                }
                ingredientList = tempArray;
                return ingredient;
            }
        }
        return null;
    }

    /**
     * remove the given ingredient from the recipe. If the ingredient is part of the
     * recipe return it, else return null.
     */
    public RecipeIngredient removeRecipeIngredient(String ingredientName) {

        for (RecipeIngredient ingredient : ingredientList) {
            if (ingredient.getName().equals(ingredientName)) {
                RecipeIngredient[] tempArray = new RecipeIngredient[ingredientList.length - 1];
                int tempArrayIndex = 0;
                for (RecipeIngredient ing : ingredientList) {
                    if (!(ing.getName().equals(ingredientName))) {
                        tempArray[tempArrayIndex] = new RecipeIngredient(ing.getName(), ing.getMeasuringUnit(),
                                ing.getCalories(), ing.getQuantity());
                        tempArrayIndex++;
                    }
                }
                ingredientList = tempArray;
                return ingredient;
            }
        }
        return null;
    }

    /**
     * calculates the sum of the calories for all the ingredients in the recipes and
     * their respective quantities.
     */
    public float calculateCalories() {
        float totalCalories = 0;
        for (RecipeIngredient ingredient : ingredientList) {
            totalCalories += (ingredient.getCalories() * ingredient.getQuantity());
        }
        return totalCalories;
    }

    /** returns the number of ingredients in the recipe. */
    public int getNumberOfIngredients() {
        return ingredientList.length;
    }

    /** returns the recipe name and ingredients as a String. */
    public String toString() {
        String ingredients = new String();
        for (RecipeIngredient ingredient : ingredientList) {
            ingredients += ingredient.toString() + "\n\n";
        }
        return name + ":\n" + ingredients;
    }

    public boolean equals(CookingRecipe recipe2) {
        if (!(this.getName().equals(recipe2.getName()))) {
            return false;
        } else if (this.getNumberOfIngredients() != recipe2.getNumberOfIngredients()) {
            return false;
        }
        RecipeIngredient[] ar1 = new RecipeIngredient[this.ingredientList.length];
        RecipeIngredient[] ar2 = new RecipeIngredient[recipe2.ingredientList.length];
        for (int i = 0; i < this.ingredientList.length; i++) {
            ar1[i] = new RecipeIngredient(this.ingredientList[i].getName(), this.ingredientList[i].getMeasuringUnit(),
                    this.ingredientList[i].getCalories(), this.ingredientList[i].getQuantity());
            ar2[i] = new RecipeIngredient(recipe2.ingredientList[i].getName(),
                    recipe2.ingredientList[i].getMeasuringUnit(), recipe2.ingredientList[i].getCalories(),
                    recipe2.ingredientList[i].getQuantity());
        }
        boolean ar1Equal = true, ar2Equal = true;
        for (RecipeIngredient ing : ar1) {
            ar1Equal = false;
            for (int i = 0; i < ar2.length; i++) {
                if (ing.equals(ar2[i])) {
                    ar1Equal = true;
                }
            }
        }
        for (RecipeIngredient ing : ar2) {
            ar2Equal = false;
            for (int i = 0; i < ar1.length; i++) {
                if (ing.equals(ar1[i])) {
                    ar2Equal = true;
                }
            }
        }
        if (ar1Equal && ar2Equal) {
            return true;
        } else {
            return false;
        }
    }
}

class RecipeBook {
    private String name;
    private CookingRecipe[] recipesList = new CookingRecipe[0];

    public RecipeBook(String initName) {
        name = initName;
    }

    /**
     * adds to the book and returns a new cooking recipe with the given parameters.
     * If recipe book already contains a recipe with the same name, do not create a
     * new one and return null.
     */
    public CookingRecipe addRecipe(String name, RecipeIngredient[] ingredients) {
        CookingRecipe newCR = new CookingRecipe(name);
        for (RecipeIngredient ings : ingredients) {
            newCR.addOrUpdateRecipeIngredient(((Ingredient) ings), ings.getQuantity());
        }
        boolean exists = false;

        for (CookingRecipe recipe : recipesList) {
            if (recipe.getName().equals(name)) {
                exists = true;
                return null;
            }
        }

        if (!exists) {
            CookingRecipe[] tempList = new CookingRecipe[recipesList.length + 1];
            for (int i = 0; i < recipesList.length; i++) {
                tempList[i] = recipesList[i];
            }
            tempList[tempList.length - 1] = newCR;
            recipesList = tempList;
        }
        return newCR;
    }

    /**
     * removes the cooking recipe from the cooking book and returns it. If recipe
     * book does not contain a recipe with the specified name, then return null.
     */
    public CookingRecipe removeRecipe(String recipeName) {
        for (CookingRecipe recipe : recipesList) {
            if (recipe.getName().equals(recipeName)) {
                CookingRecipe[] tempArray = new CookingRecipe[recipesList.length - 1];
                int tempArrayIndex = 0;
                for (CookingRecipe rec : recipesList) {
                    if (!(rec.getName().equals(recipeName))) {
                        tempArray[tempArrayIndex] = rec;
                        tempArrayIndex++;
                    }
                }
                recipesList = tempArray;
                return recipe;
            }
        }
        return null;
    }

    /**
     * returns all cooking recipes from the cooking book that contain all the
     * ingredients passed as parameters. If recipe book does not contain any recipe
     * with the specified ingredients, then return null.
     */
    public CookingRecipe[] findRecipes(RecipeIngredient[] ingredients) {
        CookingRecipe[] toReturn = new CookingRecipe[30];
        int index = 0;

        for (CookingRecipe recipe : recipesList) {
            for (RecipeIngredient ing : ingredients) {
                boolean has = false;
                for (Ingredient ing2 : recipe.ingredientList) {
                    if (ing == ing2) {
                        has = true;
                    }
                    if (has == false) {
                        continue;
                    }
                }
                if (has == true) {
                    toReturn[index] = recipe;
                    index++;
                }
            }
        }

        if (index == 0) {
            return null;
        } else {
            return toReturn;
        }
    }

    /**
     * returns all cooking recipes from the cooking book that contain less than or
     * equal the number of ingredients passed as parameter. If recipe book does not
     * contain any recipe with the specified number of ingredients, then return
     * null.
     */
    public CookingRecipe[] findRecipesWithFewIngredients(int numberOfIngredients) {
        CookingRecipe[] toReturn = new CookingRecipe[30];
        int index = 0;
        for (CookingRecipe recipe : recipesList) {
            if (recipe.getNumberOfIngredients() <= numberOfIngredients) {
                toReturn[index] = recipe;
                index++;
            }
        }
        if (index == 0) {
            return null;
        } else {
            return toReturn;
        }
    }

    /**
     * returns all cooking recipes from the cooking book that have the lowest number
     * of calories. Note: this can be multiple recipes.
     */
    public CookingRecipe[] findRecipesLowCalories() {
        CookingRecipe[] toReturn = new CookingRecipe[3];
        int index = 0;
        float lowest = recipesList[0].calculateCalories();
        for (CookingRecipe recipe : recipesList) {
            if (recipe.calculateCalories() < lowest) {
                lowest = recipe.calculateCalories();
            }
        }
        for (CookingRecipe recipe : recipesList) {
            if (recipe.calculateCalories() == lowest) {
                toReturn[index] = recipe;
                index++;
            }
        }
        return toReturn;
    }

    public String toString() {
        String recipes = new String();
        for (CookingRecipe recipe : recipesList) {
            recipes += recipe.toString() + "\n\n";
        }
        return name + recipes;
    }
}

public class TestRecipeBook {
    public static void main(String[] args) {
        Ingredient unsaltedButter = new Ingredient("Unsalted butter", "Tablespoons", 102);
        Ingredient granulatedSugar = new Ingredient("Granulated sugar", "Cups", 774);
        Ingredient cocoaPowder = new Ingredient("Unsweetened cocoa powder", "cups", 196);
        Ingredient kosherSalt = new Ingredient("Kosher salt", "Teaspoon", 0);
        Ingredient vanillaExtract = new Ingredient("Vanilla extract", "Teaspoon", 12);
        Ingredient egg = new Ingredient("Large Egg", "Number", 78);
        Ingredient flour = new Ingredient("Flour", "Cups", 455);
        Ingredient milk = new Ingredient("Milk", "Cups", 103);

        CookingRecipe brownies = new CookingRecipe("Fudge Brownies");

        CookingRecipe clone1 = new CookingRecipe("Clone1");
        CookingRecipe clone2 = new CookingRecipe("Clone1");

        clone1.addOrUpdateRecipeIngredient(egg, 2);
        clone1.addOrUpdateRecipeIngredient(flour, 3);

        clone2.addOrUpdateRecipeIngredient(flour, 3);
        clone2.addOrUpdateRecipeIngredient(egg, 2);

        if (clone1.equals(clone2)) {
            System.out.println("Recipe clone1 is the same as clone2.\n");
        } else {
            System.out.println("Recipe clone1 is not the same as clone2.\n");
        }

        brownies.addOrUpdateRecipeIngredient(unsaltedButter, 5);
        brownies.addOrUpdateRecipeIngredient(unsaltedButter, 10); // Update quantity
        brownies.addOrUpdateRecipeIngredient(granulatedSugar, (float) 1.25);
        brownies.addOrUpdateRecipeIngredient(cocoaPowder, (float) 0.75);
        brownies.addOrUpdateRecipeIngredient(kosherSalt, (float) 0.25);
        brownies.addOrUpdateRecipeIngredient(vanillaExtract, 1);
        brownies.addOrUpdateRecipeIngredient(egg, 2);
        brownies.addOrUpdateRecipeIngredient(flour, (float) 0.5);
        brownies.addOrUpdateRecipeIngredient(milk, 3);
        brownies.removeRecipeIngredient(milk);
        brownies.addOrUpdateRecipeIngredient(milk, 3);
        brownies.removeRecipeIngredient("Milk");

        System.out.println(brownies);
        System.out.println(brownies.calculateCalories());

        RecipeBook myCookBook = new RecipeBook("My Cookbook");
        RecipeIngredient[] ingArray = new RecipeIngredient[2];
        ingArray[0] = new RecipeIngredient(milk.getName(), milk.getMeasuringUnit(), milk.getCalories(), 2);
        ingArray[0] = new RecipeIngredient(cocoaPowder.getName(), cocoaPowder.getMeasuringUnit(),
                cocoaPowder.getCalories(), 2);

        myCookBook.addRecipe("Chocolate Milk", ingArray);

        System.out.println(myCookBook.toString());
    }
}
