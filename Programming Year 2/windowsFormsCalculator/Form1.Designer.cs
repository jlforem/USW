namespace windowsFormsCalculator
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            textBox1 = new TextBox();
            button1 = new Button();
            button2 = new Button();
            button3 = new Button();
            button4 = new Button();
            button5 = new Button();
            button6 = new Button();
            button7 = new Button();
            button8 = new Button();
            button9 = new Button();
            button0 = new Button();
            decimalPoint = new Button();
            resetC = new Button();
            add = new Button();
            subtract = new Button();
            multiply = new Button();
            divide = new Button();
            equals = new Button();
            SuspendLayout();
            // 
            // textBox1
            // 
            textBox1.Location = new Point(16, 12);
            textBox1.Name = "textBox1";
            textBox1.RightToLeft = RightToLeft.Yes;
            textBox1.Size = new Size(338, 23);
            textBox1.TabIndex = 0;
            textBox1.Text = "0";
            // 
            // button1
            // 
            button1.Location = new Point(16, 46);
            button1.Name = "button1";
            button1.Size = new Size(80, 80);
            button1.TabIndex = 1;
            button1.Text = "1";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.Location = new Point(102, 46);
            button2.Name = "button2";
            button2.Size = new Size(80, 80);
            button2.TabIndex = 2;
            button2.Text = "2";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Location = new Point(188, 46);
            button3.Name = "button3";
            button3.Size = new Size(80, 80);
            button3.TabIndex = 3;
            button3.Text = "3";
            button3.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            button4.Location = new Point(16, 132);
            button4.Name = "button4";
            button4.Size = new Size(80, 80);
            button4.TabIndex = 4;
            button4.Text = "4";
            button4.UseVisualStyleBackColor = true;
            // 
            // button5
            // 
            button5.Location = new Point(102, 132);
            button5.Name = "button5";
            button5.Size = new Size(80, 80);
            button5.TabIndex = 5;
            button5.Text = "5";
            button5.UseVisualStyleBackColor = true;
            // 
            // button6
            // 
            button6.Location = new Point(188, 132);
            button6.Name = "button6";
            button6.Size = new Size(80, 80);
            button6.TabIndex = 6;
            button6.Text = "6";
            button6.UseVisualStyleBackColor = true;
            // 
            // button7
            // 
            button7.Location = new Point(16, 218);
            button7.Name = "button7";
            button7.Size = new Size(80, 80);
            button7.TabIndex = 7;
            button7.Text = "7";
            button7.UseVisualStyleBackColor = true;
            // 
            // button8
            // 
            button8.Location = new Point(102, 218);
            button8.Name = "button8";
            button8.Size = new Size(80, 80);
            button8.TabIndex = 8;
            button8.Text = "8";
            button8.UseVisualStyleBackColor = true;
            // 
            // button9
            // 
            button9.Location = new Point(188, 218);
            button9.Name = "button9";
            button9.Size = new Size(80, 80);
            button9.TabIndex = 9;
            button9.Text = "9";
            button9.UseVisualStyleBackColor = true;
            // 
            // button0
            // 
            button0.Location = new Point(102, 304);
            button0.Name = "button0";
            button0.Size = new Size(80, 80);
            button0.TabIndex = 10;
            button0.Text = "0";
            button0.UseVisualStyleBackColor = true;
            button0.Click += button0_Click;
            // 
            // decimalPoint
            // 
            decimalPoint.Location = new Point(188, 304);
            decimalPoint.Name = "decimalPoint";
            decimalPoint.Size = new Size(80, 80);
            decimalPoint.TabIndex = 11;
            decimalPoint.Text = ".";
            decimalPoint.UseVisualStyleBackColor = true;
            decimalPoint.Click += decimalPoint_Click;
            // 
            // resetC
            // 
            resetC.Location = new Point(16, 304);
            resetC.Name = "resetC";
            resetC.Size = new Size(80, 80);
            resetC.TabIndex = 12;
            resetC.Text = "C";
            resetC.UseVisualStyleBackColor = true;
            resetC.Click += resetC_Click;
            // 
            // add
            // 
            add.Location = new Point(274, 46);
            add.Name = "add";
            add.Size = new Size(80, 80);
            add.TabIndex = 13;
            add.Text = "+";
            add.UseVisualStyleBackColor = true;
            add.Click += add_Click;
            // 
            // subtract
            // 
            subtract.Location = new Point(274, 132);
            subtract.Name = "subtract";
            subtract.Size = new Size(80, 80);
            subtract.TabIndex = 14;
            subtract.Text = "-";
            subtract.UseVisualStyleBackColor = true;
            subtract.Click += subtract_Click;
            // 
            // multiply
            // 
            multiply.Location = new Point(274, 218);
            multiply.Name = "multiply";
            multiply.Size = new Size(80, 80);
            multiply.TabIndex = 15;
            multiply.Text = "*";
            multiply.UseVisualStyleBackColor = true;
            multiply.Click += multiply_Click;
            // 
            // divide
            // 
            divide.Location = new Point(274, 304);
            divide.Name = "divide";
            divide.Size = new Size(80, 80);
            divide.TabIndex = 16;
            divide.Text = "/";
            divide.UseVisualStyleBackColor = true;
            divide.Click += divide_Click;
            // 
            // equals
            // 
            equals.Location = new Point(16, 390);
            equals.Name = "equals";
            equals.Size = new Size(338, 80);
            equals.TabIndex = 17;
            equals.Text = "=";
            equals.UseVisualStyleBackColor = true;
            equals.Click += equals_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(369, 482);
            Controls.Add(equals);
            Controls.Add(divide);
            Controls.Add(multiply);
            Controls.Add(subtract);
            Controls.Add(add);
            Controls.Add(resetC);
            Controls.Add(decimalPoint);
            Controls.Add(button0);
            Controls.Add(button9);
            Controls.Add(button8);
            Controls.Add(button7);
            Controls.Add(button6);
            Controls.Add(button5);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(textBox1);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox textBox1;
        private Button button1;
        private Button button2;
        private Button button3;
        private Button button4;
        private Button button5;
        private Button button6;
        private Button button7;
        private Button button8;
        private Button button9;
        private Button button0;
        private Button decimalPoint;
        private Button resetC;
        private Button add;
        private Button subtract;
        private Button multiply;
        private Button divide;
        private Button equals;
    }
}
