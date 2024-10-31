namespace vendingMachine
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.redBullButton = new System.Windows.Forms.Button();
            this.lucozadeButton = new System.Windows.Forms.Button();
            this.fantaButton = new System.Windows.Forms.Button();
            this.drPepperButton = new System.Windows.Forms.Button();
            this.spriteButton = new System.Windows.Forms.Button();
            this.cokeButton = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.AutoSize = true;
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.Controls.Add(this.redBullButton, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.lucozadeButton, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.fantaButton, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.drPepperButton, 2, 0);
            this.tableLayoutPanel1.Controls.Add(this.spriteButton, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.cokeButton, 0, 0);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(13, 13);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(225, 150);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // redBullButton
            // 
            this.redBullButton.AutoSize = true;
            this.redBullButton.Location = new System.Drawing.Point(153, 78);
            this.redBullButton.Name = "redBullButton";
            this.redBullButton.Size = new System.Drawing.Size(68, 69);
            this.redBullButton.TabIndex = 5;
            this.redBullButton.Text = "Red Bull";
            this.redBullButton.UseVisualStyleBackColor = true;
            this.redBullButton.Click += new System.EventHandler(this.redBullButton_Click);
            // 
            // lucozadeButton
            // 
            this.lucozadeButton.AutoSize = true;
            this.lucozadeButton.Location = new System.Drawing.Point(78, 78);
            this.lucozadeButton.Name = "lucozadeButton";
            this.lucozadeButton.Size = new System.Drawing.Size(68, 69);
            this.lucozadeButton.TabIndex = 4;
            this.lucozadeButton.Text = "Lucozade";
            this.lucozadeButton.UseVisualStyleBackColor = true;
            this.lucozadeButton.Click += new System.EventHandler(this.lucozadeButton_Click);
            // 
            // fantaButton
            // 
            this.fantaButton.AutoSize = true;
            this.fantaButton.Location = new System.Drawing.Point(3, 78);
            this.fantaButton.Name = "fantaButton";
            this.fantaButton.Size = new System.Drawing.Size(68, 69);
            this.fantaButton.TabIndex = 3;
            this.fantaButton.Text = "Fanta";
            this.fantaButton.UseVisualStyleBackColor = true;
            this.fantaButton.Click += new System.EventHandler(this.fantaButton_Click);
            // 
            // drPepperButton
            // 
            this.drPepperButton.AutoSize = true;
            this.drPepperButton.Location = new System.Drawing.Point(153, 3);
            this.drPepperButton.Name = "drPepperButton";
            this.drPepperButton.Size = new System.Drawing.Size(68, 69);
            this.drPepperButton.TabIndex = 2;
            this.drPepperButton.Text = "Dr. Pepper";
            this.drPepperButton.UseVisualStyleBackColor = true;
            this.drPepperButton.Click += new System.EventHandler(this.drPepperButton_Click);
            // 
            // spriteButton
            // 
            this.spriteButton.AutoSize = true;
            this.spriteButton.Location = new System.Drawing.Point(78, 3);
            this.spriteButton.Name = "spriteButton";
            this.spriteButton.Size = new System.Drawing.Size(68, 69);
            this.spriteButton.TabIndex = 1;
            this.spriteButton.Text = "Sprite";
            this.spriteButton.UseVisualStyleBackColor = true;
            this.spriteButton.Click += new System.EventHandler(this.spriteButton_Click);
            // 
            // cokeButton
            // 
            this.cokeButton.AutoSize = true;
            this.cokeButton.Location = new System.Drawing.Point(3, 3);
            this.cokeButton.Name = "cokeButton";
            this.cokeButton.Size = new System.Drawing.Size(68, 69);
            this.cokeButton.TabIndex = 0;
            this.cokeButton.Text = "Coca Cola";
            this.cokeButton.UseVisualStyleBackColor = true;
            this.cokeButton.Click += new System.EventHandler(this.cokeButton_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(91, 166);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(68, 69);
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Location = new System.Drawing.Point(91, 241);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(68, 69);
            this.pictureBox2.TabIndex = 2;
            this.pictureBox2.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(602, 450);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Button lucozadeButton;
        private System.Windows.Forms.Button fantaButton;
        private System.Windows.Forms.Button drPepperButton;
        private System.Windows.Forms.Button spriteButton;
        private System.Windows.Forms.Button cokeButton;
        private System.Windows.Forms.Button redBullButton;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
    }
}

