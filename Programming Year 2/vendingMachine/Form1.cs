﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace vendingMachine
{
    public partial class Form1 : Form
    {
        private basketHandler basket;

        public Form1()
        {
            InitializeComponent();
            VendingStock coke = new VendingStock("Coke", 2.50m, 8);
            VendingStock sprite = new VendingStock("Sprite", 1.95m, 5);
            VendingStock drPepper = new VendingStock("Dr Pepper", 2.10m, 1);
            VendingStock fanta = new VendingStock("Fanta", 1.90m, 10);
            VendingStock lucozade = new VendingStock("Lucozade", 2.20m, 7);
            VendingStock redBull = new VendingStock("Red Bull", 2.60m, 9);

            basket = new basketHandler();
        }

        private void UpdateTotalPriceLabel()
        {
            totalPriceLabelUpdateable.Text = $"Total Price: £{basket.GetTotalPrice():0.00}";
        }

        private void UpdateItemBasketTextBox()
        {
            itemBasketRichTextBox.Clear();
            foreach (var item in basket.GetBasketItems())
            {
                itemBasketRichTextBox.AppendText($"{item.Key} - £{item.Value.price:0.00} - {item.Value.quantity}\n");
            }
        }

        private void cokeButton_Click(object sender, EventArgs e)
        {
            basket.addToBasket("Coke", 2.50m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void spriteButton_Click(object sender, EventArgs e)
        {
            basket.addToBasket("Sprite", 1.95m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void drPepperButton_Click(object sender, EventArgs e)
        {
            basket.addToBasket("Dr Pepper", 2.10m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void fantaButton_Click(object sender, EventArgs e)
        {
            basket.addToBasket("Fanta", 1.90m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void lucozadeButton_Click(object sender, EventArgs e)
        {
            basket.addToBasket("Lucozade", 2.20m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void redBullButton_Click(object sender, EventArgs e)
        {
            basket.addToBasket("Red Bull", 2.60m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            basket.clearBasket();
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void itemBasketTextBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void totalPriceLabelUpdateable_Click(object sender, EventArgs e)
        {

        }
        
    }

    public class VendingStock
    {
        string name = " ";
        decimal price = 0.0m;
        int quantityRemaining = 0;
        event EventHandler buttonClick;

        public VendingStock(string name, decimal price, int quantityRemaining)
        {
            this.name = name;
            this.price = price;
            this.quantityRemaining = quantityRemaining;
        }

        public string getName()
        {
            return name;
        }

        public decimal getPrice()
        {
            return price;
        }

        public int getQuantityRemaining()
        {
            return quantityRemaining;
        }

        public void buttonClickAction(object sender, EventArgs e)
        {
            buttonClick?.Invoke(this, e);

            if (quantityRemaining > 0)
            {
                quantityRemaining-= 1;
                MessageBox.Show("You have purchased a " + name + " for " + price + "p");
            }
            else
            {
                MessageBox.Show("Sorry, we are out of " + name);
            }
        }
    }

    public class basketHandler
    {
        decimal totalPrice = 0.0m;
        Dictionary<string, (decimal price, int quantity)> basketItems = new Dictionary<string, (decimal price, int quantity)>();

        public void addToBasket(string item, decimal price)
        {
            if (basketItems.ContainsKey(item))
            {
                basketItems[item] = (price, basketItems[item].quantity + 1);
            }
            else
            {
                basketItems[item] = (price, 1);
            }
            totalPrice += price;
        }

        public void removeFromBasket(string item, decimal price)
        {
            if (basketItems.ContainsKey(item))
            {
                if (basketItems[item].quantity > 1)
                {
                    basketItems[item] = (price, basketItems[item].quantity - 1);
                }
                else
                {
                    basketItems.Remove(item);
                }
                totalPrice -= price;
            }
        }

        public void clearBasket()
        {
            basketItems.Clear();
            totalPrice = 0.0m;
        }

        public decimal GetTotalPrice()
        {
            return totalPrice;
        }

        public Dictionary<string, (decimal price, int quantity)> GetBasketItems()
        {
            return basketItems;
        }
    }

    
}