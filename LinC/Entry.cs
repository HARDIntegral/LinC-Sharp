using System;
using System.Runtime.InteropServices;

namespace LinC {
    class Entry {
        [StructLayout(LayoutKind.Sequential, Pack=1)]
        struct vars_t {
            int num_vars;
            unsafe void** vars;
        };

        // Functions are named in the context of the C bridge
        [DllImport(@"./c_bridge.so")]
        public static extern void bridge_init();
        [DllImport(@"./c_bridge.so")]
        public static extern unsafe void receive_data(void* data, int type);

        // Wrapper methods
        static unsafe void send<T>(ref T data) where T: unmanaged {
            fixed (T* data_ref = &data) {
                receive_data(data_ref, 1);
            };
        }

        static void Main(string[] args) {
            bridge_init();
            Console.WriteLine("Hello, world!");

            int test = 5;
            send(ref test);
        }
    } 
}
