namespace test1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void clickMe_Click(object sender, EventArgs e)
        {
            MessageBox.Show("button1 clicked");
            MessageBox.Show(sender.ToString());
            MessageBox.Show(((Button)sender).Text);
            MessageBox.Show(e.ToString());
            MessageBox.Show((((MouseEventArgs)e).Location).ToString());
        }
    }
}
