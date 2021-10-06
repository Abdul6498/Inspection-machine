using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;

namespace arduinoCommunication
{
    public partial class Main : Form
    {
        SerialPort port;
        int accept_stock = 0;
        int reject_stock = 0;
        /// <summary>
        /// Safely run code inside try catch.
        /// </summary>
        /// <param name="action">Code</param>
        /// <param name="message">Display error message</param>
        public void SafeAction(Action action, bool message=true)
        {
            try
            {
                action();
            }
            catch (Exception ex)
            {
                if (message)
                {
                    MessageBox.Show(ex.Message, "Exception", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        /// <summary>
        /// Start serial communication with Arduino board.
        /// </summary>
        /// <param name="listeningPort">Listening Port</param>
        /// <param name="baudRate">Baud Rate</param>
        public void InitializeArduino(String listeningPort, int baudRate) 
        {
            SafeAction(() =>
            {
                port = new SerialPort(listeningPort, baudRate);
                port.Parity = Parity.None;
                port.StopBits = StopBits.One;
                port.DataBits = 8;
                port.Handshake = Handshake.None;
                port.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

                port.Open();
            });
        }

        /// <summary>
        /// Called when there is new data coming in.
        /// </summary>
        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string line = sp.ReadLine();
            this.BeginInvoke(new LineReceivedEvent(LineReceived), line);
        }

        private delegate void LineReceivedEvent(string line);

        private void LineReceived(string line)
        {
            
           // txtLog.Text = txtLog.Text + line + "\n";
            //count_box.Text = "Your stock is = " + line;
            if (line == "cam1")
            {
                string display = "Bottle is at cam 1";
                //accept_stock++;
                //count_box.Text = "Your stock is = " + accept_stock.ToString();
                //count_box.Text = accept_stock.ToString();
                cam1_box.Text = display + "\n";
                txtLog.Text = txtLog.Text + display + "\t\t\t\t";
            }
            if (line == "cam1_clear")
            {
                cam1_box.Clear();
            }

            if (line == "cam2")
            {
                string display = "Bottle is at cam 2";
                //accept_stock++;
                //count_box.Text = "Your stock is = " + accept_stock.ToString();
                //count_box.Text = accept_stock.ToString();
                cam2_box.Text = display;
                txtLog.Text = txtLog.Text + display + "\t\t\t\t";
            }
            if (line == "cam2_clear")
            {
                cam2_box.Clear();
            }

            if (line == "servo")
            {
                string display = "Bottle is at Seal Check";
                //accept_stock++;
               // count_box.Text = "Your stock is = " + accept_stock.ToString();
                //count_box.Text = accept_stock.ToString();
                servo_box.Text = display;
                txtLog.Text = txtLog.Text + display + "\t\t\t";
            }
            if (line == "servo_clear")
            {
                servo_box.Clear();
            }

            if (line == "actuator")
            {
                string display = "Bottle is at Actuator stage";
                //accept_stock++;
                // count_box.Text = "Your stock is = " + accept_stock.ToString();
                //count_box.Text = accept_stock.ToString();
                actuator_box.Text = display;
                txtLog.Text = txtLog.Text + display + "\t\t\t";
            }
            if (line == "actuator_clear")
            {
                actuator_box.Clear();
            }

            if (line == "accept")
            {
                string display = "Bottle is Accepted";
                accept_stock++;
                count_box.Text = "Your accepted stock is = " + accept_stock.ToString();
                //count_box.Text = accept_stock.ToString();
                //actuator_box.Text = display;
                txtLog.Text = txtLog.Text + display + "\t\t\t\t";
            }
            if (line == "reject")
            {
                string display = "Bottle is Rejected";
                reject_stock++;
                reject_box.Text = "Your rejected stock is = " + reject_stock.ToString();
                txtLog.Text = txtLog.Text + display + "\t\t\t\t";
            }
            if (line == "unseal")
            {
                string display = "Bottle is Rejected beacuse bottle is not sealed";
                //reject_stock++;
                //reject_box.Text = "Your rejected stock is = " + reject_stock.ToString();
                txtLog.Text = txtLog.Text + display + "\n";
            }
            if (line == "uncap")
            {
                string display = "Bottle is Rejected beacuse cap is not present";
                //reject_stock++;
                //reject_box.Text = "Your rejected stock is = " + reject_stock.ToString();
                txtLog.Text = txtLog.Text + display + "\n";
            }
        }

        public Main()
        {
            InitializeComponent();
            con_on.Enabled = true;
            con_off.Enabled = false;
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtLog.Text = null;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();

            foreach (string port in ports)
            {
                cmbPorts.Items.Add(port);
            }
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            SafeAction(() => InitializeArduino(cmbPorts.Text, Convert.ToInt32(txtBaudRate.Text)) );
        }

        private void btnSend_Click(object sender, EventArgs e)
        {
            SafeAction(() =>
            {
                String s = txtSend.Text;
                port.Write(s);
            });
        }

        private void Main_FormClosing(object sender, FormClosingEventArgs e)
        {
            SafeAction(() => port.Close(), false);       
        }

        private void txtLog_TextChanged(object sender, EventArgs e)
        {
            txtLog.SelectionStart = txtLog.Text.Length;
            txtLog.ScrollToCaret();
        }

        private void con_on_Click(object sender, EventArgs e)
        {
            port.Write("Q");
            con_on.Enabled = false;
            con_off.Enabled = true;
            
        }

        private void con_off_Click(object sender, EventArgs e)
        {
            port.Write("A");
            con_on.Enabled = true;
            con_off.Enabled = false;
            
        }

    }
}
