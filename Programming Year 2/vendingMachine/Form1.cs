using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace vendingMachine
{
    public partial class SN17033128 : Form
    {
        private basketHandler basket;

        private VendingStock coke;
        private VendingStock sprite;
        private VendingStock drPepper;
        private VendingStock fanta;
        private VendingStock lucozade;
        private VendingStock redBull;

        private decimal totalRemaining = 0.0m;

        public SN17033128()
        {
            InitializeComponent();
            coke = new VendingStock("Coke", 2.50m, 8);
            sprite = new VendingStock("Sprite", 1.95m, 5);
            drPepper = new VendingStock("Dr Pepper", 2.10m, 1);
            fanta = new VendingStock("Fanta", 1.90m, 10);
            lucozade = new VendingStock("Lucozade", 2.20m, 7);
            redBull = new VendingStock("Red Bull", 2.60m, 9);

            basket = new basketHandler();
        }

        private void buttonClickQuantityChange(VendingStock vendingStock)
        {
            if (vendingStock.getQuantityRemaining() > 0)
            {
                vendingStock.quantityRemaining -= 1;
                UpdateButtonText(vendingStock);
            }
            else
            {
                MessageBox.Show($"That was the last of the {vendingStock.getName()}! ");
                // Disable the button
                if (vendingStock == coke)
                {
                    cokeButton.Enabled = false;
                    cokeButton.Text = $"Coke ({coke.getQuantityRemaining()})";
                }
                else if (vendingStock == sprite)
                {
                    spriteButton.Enabled = false;
                    spriteButton.Text = $"Sprite ({sprite.getQuantityRemaining()})";
                }
                else if (vendingStock == drPepper)
                {
                    drPepperButton.Enabled = false;
                    drPepperButton.Text = $"Dr Pepper ({drPepper.getQuantityRemaining()})";
                }
                else if (vendingStock == fanta)
                {
                    fantaButton.Enabled = false;
                    fantaButton.Text = $"Fanta ({fanta.getQuantityRemaining()})";
                }
                else if (vendingStock == lucozade)
                {
                    lucozadeButton.Enabled = false;
                    lucozadeButton.Text = $"Lucozade ({lucozade.getQuantityRemaining()})";
                }
                else if (vendingStock == redBull)
                {
                    redBullButton.Enabled = false;
                    redBullButton.Text = $"Red Bull ({redBull.getQuantityRemaining()})";
                }
            }
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

        private void UpdateButtonText(VendingStock vendingStock)
        {
            if (vendingStock == coke)
            {
                cokeButton.Text = $"Coke ({coke.getQuantityRemaining()})";
            }
            else if (vendingStock == sprite)
            {
                spriteButton.Text = $"Sprite ({sprite.getQuantityRemaining()})";
            }
            else if (vendingStock == drPepper)
            {
                drPepperButton.Text = $"Dr Pepper ({drPepper.getQuantityRemaining()})";
            }
            else if (vendingStock == fanta)
            {
                fantaButton.Text = $"Fanta ({fanta.getQuantityRemaining()})";
            }
            else if (vendingStock == lucozade)
            {
                lucozadeButton.Text = $"Lucozade ({lucozade.getQuantityRemaining()})";
            }
            else if (vendingStock == redBull)
            {
                redBullButton.Text = $"Red Bull ({redBull.getQuantityRemaining()})";
            }
        }

        private void UpdateButtonLabels()
        {
            cokeButton.Enabled = true;
            cokeButton.Text = $"Coke ({coke.getQuantityRemaining()})";

            spriteButton.Enabled = true;
            spriteButton.Text = $"Sprite ({sprite.getQuantityRemaining()})";

            drPepperButton.Enabled = true;
            drPepperButton.Text = $"Dr Pepper ({drPepper.getQuantityRemaining()})";

            fantaButton.Enabled = true;
            fantaButton.Text = $"Fanta ({fanta.getQuantityRemaining()})";

            lucozadeButton.Enabled = true;
            lucozadeButton.Text = $"Lucozade ({lucozade.getQuantityRemaining()})";

            redBullButton.Enabled = true;
            redBullButton.Text = $"Red Bull ({redBull.getQuantityRemaining()})";
        }

        private void clearButton_Check()
        {
            if (totalPriceLabelUpdateable.Text == $"Total Price: £0.00")
            {
                clearButton.Enabled = false;
            }
            else
            {
                clearButton.Enabled = true;
            }
        }
        
        public void clearButton_Click(object sender, EventArgs e)
        {
            // Clear the basket and add the quantity remaining back to the VendingMachine objects
            foreach (var item in basket.GetBasketItems())
            {
                string itemName = item.Key;
                int quantity = item.Value.quantity;

                if (itemName == "Coke")
                {
                    coke.quantityRemaining += quantity;
                }
                else if (itemName == "Sprite")
                {
                    sprite.quantityRemaining += quantity;
                }
                else if (itemName == "Dr Pepper")
                {
                    drPepper.quantityRemaining += quantity;
                }
                else if (itemName == "Fanta")
                {
                    fanta.quantityRemaining += quantity;
                }
                else if (itemName == "Lucozade")
                {
                    lucozade.quantityRemaining += quantity;
                }
                else if (itemName == "Red Bull")
                {
                    redBull.quantityRemaining += quantity;
                }
            }
            basket.clearBasket();
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
            UpdateButtonLabels();
            clearButton_Check();
        }
        
        /*
         Portion that deals with checkout button and money insertion
         */
        private void checkoutButton_Click(object sender, EventArgs e)
        {
            totalRemaining = basket.GetTotalPrice();

            if (totalRemaining == 0.0m)
            {
                MessageBox.Show("Thanks for shopping!");
                Application.Exit();
            }
        }

        private void coinSlotImage_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.Text))
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void coinSlotImage_DragDrop(object sender, DragEventArgs e)
        {
            string moneyType = e.Data.GetData(DataFormats.Text).ToString();
            decimal moneyValue = GetMoneyValue(moneyType);

            totalRemaining -= moneyValue;
            totalRemainingLabel.Text = $"Total Remaining: £{totalRemaining:0.00}";

            if (totalRemaining <= 0.0m)
            {
                checkoutButton.Enabled = true;
            }
        }
        /*
         FUTURE JORDAN ADD ALL THIS COIN STUFF TO A NEW CHECKOUT CLASS THIS IS SO DAMN CONFUSING TO LOOK AT MY DUDE, MAKE IT ALL PUBLIC IF YA NEED TO
         */
        private decimal GetMoneyValue(string moneyType)
        {
            switch (moneyType)
            {
                case "money1000":
                    return 10.0m;
                case "money500":
                    return 5.0m;
                case "money100":
                    return 1.0m;
                case "money50":
                    return 0.50m;
                case "money20":
                    return 0.20m;
                case "money10":
                    return 0.10m;
                case "money5":
                    return 0.5m;
                case "money2":
                    return 0.2m;
                case "money1":
                    return 0.1m;
                default:
                    return 0.0m;
            }
        }

        /*
         All of the drag events for the money images
         */
        private void money1000_dragdrop(object sender, EventArgs e)
        {
            
        }

        private void money500_dragdrop(object sender, EventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            DoDragDrop(pictureBox.Name, DragDropEffects.Copy);
        }

        private void money100_dragdrop(object sender, EventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            DoDragDrop(pictureBox.Name, DragDropEffects.Copy);
        }

        private void money50_dragdrop(object sender, EventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            DoDragDrop(pictureBox.Name, DragDropEffects.Copy);
        }

        private void money20_dragdrop(object sender, EventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            DoDragDrop(pictureBox.Name, DragDropEffects.Copy);
        }

        private void money10_dragdrop(object sender, EventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            DoDragDrop(pictureBox.Name, DragDropEffects.Copy);
        }

        private void money5_dragdrop(object sender, EventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            DoDragDrop(pictureBox.Name, DragDropEffects.Copy);
        }

        private void money2_dragdrop(object sender, MouseEventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            DoDragDrop(pictureBox.Name, DragDropEffects.Copy);
        }

        private void money1_dragdrop(object sender, MouseEventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            DoDragDrop(pictureBox.Name, DragDropEffects.Copy);
        }

        /*
         All of the button_click events for the vending machine buttons
         */
        private void cokeButton_Click(object sender, EventArgs e)
        {
            clearButton_Check();
            buttonClickQuantityChange(coke);
            basket.addToBasket("Coke", 2.50m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void spriteButton_Click(object sender, EventArgs e)
        {
            clearButton_Check();
            buttonClickQuantityChange(sprite);
            basket.addToBasket("Sprite", 1.95m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void drPepperButton_Click(object sender, EventArgs e)
        {
            clearButton_Check();
            buttonClickQuantityChange(drPepper);
            basket.addToBasket("Dr Pepper", 2.10m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void fantaButton_Click(object sender, EventArgs e)
        {
            clearButton_Check();
            buttonClickQuantityChange(fanta);
            basket.addToBasket("Fanta", 1.90m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void lucozadeButton_Click(object sender, EventArgs e)
        {
            clearButton_Check();
            buttonClickQuantityChange(lucozade);
            basket.addToBasket("Lucozade", 2.20m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        private void redBullButton_Click(object sender, EventArgs e)
        {
            clearButton_Check();
            buttonClickQuantityChange(redBull);
            basket.addToBasket("Red Bull", 2.60m);
            UpdateTotalPriceLabel();
            UpdateItemBasketTextBox();
        }

        /**
         * I am not doing anything with these but they can stay instead of breaking the code when I remove :)
         */
        private void itemBasketTextBox_TextChanged(object sender, EventArgs e)
        {
            UpdateItemBasketTextBox();
        }

        private void totalPriceLabelUpdateable_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox9_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void totalRemainingLabel_Click(object sender, EventArgs e)
        {

        }

        private void money1000_MouseDown(object sender, MouseEventArgs e)
        {
            PictureBox pictureBox = (PictureBox)sender;
            money1000.DoDragDrop(pictureBox.Name, DragDropEffects.Copy);
        }

        
    }


    /*
         Class dealing with the stock of the vending machine
         */
    public class VendingStock
    {
        string name = " ";
        decimal price = 0.0m;
        public int quantityRemaining = 0;

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
    }

    /*
         Class dealing with the basket of the vending machine, separated for readability
         */

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

