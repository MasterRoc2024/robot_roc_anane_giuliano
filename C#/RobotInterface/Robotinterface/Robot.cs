﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Robotinterface
{
    internal class Class1
    {
        public class Robot
        {
            public string receivedText = "";
            public float distanceTelemetreDroit;
            public float distanceTelemetreCentre;
            public float distanceTelemetreGauche;

            public Queue<byte> byteListReceived = new Queue<byte>();
            public Robot()
            {
            }
        }
    }
}
