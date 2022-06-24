using System;
using System.Runtime.InteropServices;

namespace LinC {
    class Program {
        [DllImport(@"./c_bridge.so")]
        public static extern void bridge_init();

        static void Main(string[] args) {
            bridge_init();
            Console.WriteLine("Hello, world!");
        }
    } 
}
