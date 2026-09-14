using System;
using System.Runtime.InteropServices;
using Windows.Foundation;

namespace DifferentXamlBoxingBehaviorCSharp
{
    /// <summary>
    /// Hand-declared IPropertyValue.
    ///
    /// CsWinRT ships Windows.Foundation.IPropertyValue inside WinRT.Runtime.dll but keeps
    /// it <c>internal</c>, so it cannot be referenced from app code the way
    /// winrt::Windows::Foundation::IPropertyValue can in C++/WinRT. Redeclaring it here
    /// gives us the same QueryInterface-and-ask-the-type capability.
    ///
    /// Member order below must match ABI.Windows.Foundation.IPropertyValue.Vftbl exactly:
    /// IInspectable occupies vtable slots 3-5, get_Type is slot 6, get_IsNumericScalar is
    /// slot 7, and the GetXxx accessors follow from slot 8. Only the members we actually
    /// call are declared; anything past the last one declared is simply unreachable, which
    /// is fine, but nothing may be reordered or omitted from the middle.
    /// </summary>
    [ComImport]
    [Guid("4bd682dd-7554-40e9-9a9b-82654ede7e62")]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    internal interface IPropertyValue
    {
        // --- IInspectable (slots 3-5) - declared purely to align the vtable. ---
        [PreserveSig] int GetIids(out int iidCount, out IntPtr iids);
        [PreserveSig] int GetRuntimeClassName(out IntPtr className);
        [PreserveSig] int GetTrustLevel(out int trustLevel);

        // --- IPropertyValue (slot 6 onward). ---
        [PreserveSig] int get_Type(out PropertyType value);
        [PreserveSig] int get_IsNumericScalar(out byte value);
    }

    internal static class PropertyValueExtensions
    {
        /// <summary>Mirrors C++/WinRT's <c>propertyValue.Type()</c>.</summary>
        public static PropertyType Type(this IPropertyValue propertyValue)
        {
            Marshal.ThrowExceptionForHR(propertyValue.get_Type(out PropertyType value));
            return value;
        }

        /// <summary>Mirrors C++/WinRT's <c>propertyValue.IsNumericScalar()</c>.</summary>
        public static bool IsNumericScalar(this IPropertyValue propertyValue)
        {
            Marshal.ThrowExceptionForHR(propertyValue.get_IsNumericScalar(out byte value));
            return value != 0;
        }
    }
}
