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

		cm.addRecipe(r1);
		
		//Set up for r2
		r2 = new Recipe();
		r2.setName("Mocha");
		r2.setAmtChocolate("20");
		r2.setAmtCoffee("3");
		r2.setAmtMilk("1");
		r2.setAmtSugar("1");
		r2.setPrice("75");

		cm.addRecipe(r2);
		
		//Set up for r3
		r3 = new Recipe();
		r3.setName("Latte");
		r3.setAmtChocolate("0");
		r3.setAmtCoffee("3");
		r3.setAmtMilk("3");
		r3.setAmtSugar("1");
		r3.setPrice("100");

		cm.addRecipe(r3);

		//Set up for r4
		r4 = new Recipe();
		r4.setName("Hot Chocolate");
		r4.setAmtChocolate("4");
		r4.setAmtCoffee("0");
		r4.setAmtMilk("1");
		r4.setAmtSugar("1");
		r4.setPrice("65");

		cm.addRecipe(r4);
	}
	
	@Test
	public void testAddInventory_Normal() {
		try {
			cm.addInventory("4","7","0","9"); //Coffee, Milk, Sugar, Chocolate
		} catch (InventoryException e) {
			fail("InventoryException should not be thrown");
		}
		String inventory = cm.checkInventory();
		String expected = "Coffee: 19\nMilk: 22\nSugar: 15\nChocolate: 24\n";
		// We start with 15 in inventory, then added some.
		assertEquals(expected,inventory);
	}

	/*
	@Test
	public void testAddInventoryException() {
		Throwable exception = assertThrows(
				InventoryException.class, () -> {
					cm.addInventory("4", "-1", "asdf", "3"); // Should throw an InventoryException
				}
				);
	}
	 */
	
	@Test
	public void testMakeCoffee_Normal() {
		cm.addRecipe(r1);
		assertEquals(25, cm.makeCoffee(0, 75));
	}
	@Test
	public void testAddRecipe() {
		assertTrue(cm.addRecipe(r2));
	}
	@Test
	public void testDeleteRecipe() {
		String recipe = r1.getName();
		assertEquals(recipe, cm.deleteRecipe(0));
		assertEquals("",cm.deleteRecipe(0));
	}
	@Test
	public void testEditRecipe() {
		String name = r1.getName();
		assertEquals(name,cm.editRecipe(0,r2));
		assertNotEquals(name,r1.getName());
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
		assertEquals(false, inv.enoughIngredients(r1));
	}

	@Test
	public void testUseIngredientsTrue() {
		Inventory inv = new Inventory();
		int coffee = inv.getCoffee();
		inv.useIngredients(r1);
		assertEquals(false,r1);
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

}

