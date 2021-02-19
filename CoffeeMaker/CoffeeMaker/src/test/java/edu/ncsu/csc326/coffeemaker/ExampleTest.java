package edu.ncsu.csc326.coffeemaker;

import edu.ncsu.csc326.coffeemaker.exceptions.InventoryException;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertThrows;
import static org.junit.Assert.fail;

import org.junit.Before;
import org.junit.Test;

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
	
	@Test
	public void testAddInventoryException() {
		Throwable exception = assertThrows(
				InventoryException.class, () -> {
					cm.addInventory("4", "-1", "asdf", "3"); // Should throw an InventoryException
				}
				);
	}
	
	@Test
	public void testMakeCoffee_Normal() {
		cm.addRecipe(r1);
		assertEquals(25, cm.makeCoffee(0, 75));
	}

}
