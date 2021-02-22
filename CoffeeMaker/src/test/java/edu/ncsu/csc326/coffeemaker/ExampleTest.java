package edu.ncsu.csc326.coffeemaker;

import edu.ncsu.csc326.coffeemaker.exceptions.InventoryException;

import edu.ncsu.csc326.coffeemaker.exceptions.RecipeException;
import org.junit.Before;
import org.junit.Test;
import org.junit.platform.commons.util.PackageUtils;

import java.sql.SQLOutput;

import static org.junit.Assert.*;

/**
 *
 * Example Unit tests for CoffeeMaker class.
 * Do not submit as your own!
 */
public class ExampleTest {
	
	private CoffeeMaker cm;
	private Recipe r1;
	private Recipe r2;
	private Recipe r3;
	private Recipe r4;

	@Before
	public void setUp() throws Exception {
		cm = new CoffeeMaker();
		
		//Set up for r1
		r1 = new Recipe();
		r1.setName("Coffee");
		r1.setAmtChocolate("0");
		r1.setAmtCoffee("3");
		r1.setAmtMilk("1");
		r1.setAmtSugar("1");
		r1.setPrice("50");

		//Set up for r2
		r2 = new Recipe();
		r2.setName("Mocha");
		r2.setAmtChocolate("20");
		r2.setAmtCoffee("3");
		r2.setAmtMilk("1");
		r2.setAmtSugar("1");
		r2.setPrice("75");

		//Set up for r3
		r3 = new Recipe();
		r3.setName("Latte");
		r3.setAmtChocolate("0");
		r3.setAmtCoffee("3");
		r3.setAmtMilk("3");
		r3.setAmtSugar("1");
		r3.setPrice("100");

		//Set up for r4
		r4 = new Recipe();
		r4.setName("Hot Chocolate");
		r4.setAmtChocolate("4");
		r4.setAmtCoffee("0");
		r4.setAmtMilk("1");
		r4.setAmtSugar("1");
		r4.setPrice("65");

	}
	
	@Test
	public void testAddInventory() {
		try {
			cm.addInventory("5", "5","5","5");
		} catch (Exception e) {
			System.out.println("addInventory caused error, should not have");
		}
		String expected = "Coffee: 20\nMilk: 20\nSugar: 20\nChocolate: 20\n";
		// We start with 15 in inventory, then added some.
		assertEquals(expected,cm.checkInventory());
	}
	
	@Test
	public void testMakeCoffee() {
		cm.addRecipe(r1);
		assertEquals(19,cm.makeCoffee(0,69));
		assertEquals(45,cm.makeCoffee(0,45));
		cm.deleteRecipe(0);
		assertEquals(60,cm.makeCoffee(0,60));
		assertEquals(-50,cm.makeCoffee(0,-50));

	}
	@Test
	public void testAddRecipes() {
		assertTrue(cm.addRecipe(r1));
		assertTrue(cm.addRecipe(r2));
		assertTrue(cm.addRecipe(r3));
		assertTrue(cm.addRecipe(r4));
	}
	@Test
	public void testDeleteRecipe() {
		cm.addRecipe(r1);
		cm.addRecipe(r2);
		String recipe = r1.getName();
		assertEquals(recipe, cm.deleteRecipe(0));
		assertEquals(null,cm.deleteRecipe(0));
	}
	@Test
	public void testEditRecipe() {
		cm.addRecipe(r1);
		cm.addRecipe(r2);
		String name = r1.getName();
		assertEquals(name,cm.editRecipe(0,r2));
		assertNotEquals(name,cm.getRecipes()[0]);
	}
	@Test
	public void testCheckInventory() {
		assertNotNull(cm.checkInventory());
	}

	@Test
	public void testEnoughIngredients() {
		Inventory inv = new Inventory();
		assertTrue(inv.enoughIngredients(r1));
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);
		inv.useIngredients(r1);

		assertEquals(false, inv.enoughIngredients(r1));
	}

	@Test
	public void testUseIngredientsTrue() {
		Inventory inv = new Inventory();
		int coffee = inv.getCoffee();
		inv.useIngredients(r1);
		assertTrue(coffee > inv.getCoffee());
	}
	@Test
	public void testUseIngredientsFalse() throws RecipeException {
		Inventory inv = new Inventory();
		Recipe recipe = new Recipe();
		recipe.setAmtChocolate("50");
		recipe.setAmtCoffee("100");
		recipe.setAmtMilk("100");
		recipe.setAmtSugar("100");
		assertEquals(false,inv.useIngredients(recipe));
	}
	@Test
	public void testAddSugar() throws Exception {
		Inventory inv = new Inventory();
		int prevSugar = inv.getSugar();
		inv.addSugar("5");
		int newSugar = inv.getSugar();
		assertNotEquals(prevSugar,newSugar);
		assertEquals(prevSugar+5,inv.getSugar());
	}

	@Test
	public void testRecipeSetPrice() throws Exception {
		Recipe recipe = new Recipe();
		recipe.setPrice("500");
		assertEquals(500,recipe.getPrice());
		recipe.setPrice("-500");
		assertEquals(-500,recipe.getPrice());
	}

	@Test
	public void testRecipeBookAddRecipe() {
		RecipeBook recipeBook = new RecipeBook();
		assertEquals(true, recipeBook.addRecipe(r1));
		assertEquals(false, recipeBook.addRecipe(r1));
		assertEquals(r1, recipeBook.getRecipes()[0]);
	}

	@Test
	public void testRecipeGettersAndSetters() throws Exception{
		Recipe recipe = new Recipe();
		recipe.setPrice("5");
		recipe.setAmtSugar("5");
		recipe.setName("5");
		recipe.setAmtMilk("5");
		recipe.setAmtCoffee("5");
		recipe.setAmtChocolate("5");

		assertEquals(5,recipe.getPrice());
		assertEquals(5,recipe.getAmtSugar());
		assertEquals("5",recipe.getName());
		assertEquals(5,recipe.getAmtMilk());
		assertEquals(5,recipe.getAmtCoffee());
		assertEquals(5,recipe.getAmtChocolate());

	}

	@Test
	public void testInventoryGetSetAdd() throws Exception {
		Inventory inv = new Inventory();
		inv.setChocolate(10);
		inv.setCoffee(10);
		inv.setMilk(10);
		inv.setSugar(10);

		inv.addChocolate("10");
		inv.addCoffee("10");
		inv.addMilk("10");
		inv.addSugar("10");

		assertEquals(20,inv.getChocolate());
		assertEquals(20,inv.getCoffee());
		assertEquals(20,inv.getMilk());
		assertEquals(20,inv.getSugar());

	}
}

