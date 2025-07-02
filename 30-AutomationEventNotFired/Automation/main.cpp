// Defines an event handler for property-changed events, and listens for
// ToggleState property changes on the element specifies by the user.
#include <windows.h>
#include <stdio.h>
#include <UIAutomation.h>
#include <format>

constexpr static auto AutomationPropertyIdToString(PROPERTYID propertyId)
{
    switch (propertyId)
    {
    case UIA_AcceleratorKeyPropertyId: return "UIA_AcceleratorKeyPropertyId";
    case UIA_AccessKeyPropertyId: return "UIA_AccessKeyPropertyId";
    case UIA_AnnotationObjectsPropertyId: return "UIA_AnnotationObjectsPropertyId";
    case UIA_AnnotationTypesPropertyId: return "UIA_AnnotationTypesPropertyId";
    case UIA_AriaPropertiesPropertyId: return "UIA_AriaPropertiesPropertyId";
    case UIA_AriaRolePropertyId: return "UIA_AriaRolePropertyId";
    case UIA_AutomationIdPropertyId: return "UIA_AutomationIdPropertyId";
    case UIA_BoundingRectanglePropertyId: return "UIA_BoundingRectanglePropertyId";
    case UIA_CenterPointPropertyId: return "UIA_CenterPointPropertyId";
    case UIA_ClassNamePropertyId: return "UIA_ClassNamePropertyId";
    case UIA_ClickablePointPropertyId: return "UIA_ClickablePointPropertyId";
    case UIA_ControllerForPropertyId: return "UIA_ControllerForPropertyId";
    case UIA_ControlTypePropertyId: return "UIA_ControlTypePropertyId";
    case UIA_CulturePropertyId: return "UIA_CulturePropertyId";
    case UIA_DescribedByPropertyId: return "UIA_DescribedByPropertyId";
    case UIA_FillColorPropertyId: return "UIA_FillColorPropertyId";
    case UIA_FillTypePropertyId: return "UIA_FillTypePropertyId";
    case UIA_FlowsFromPropertyId: return "UIA_FlowsFromPropertyId";
    case UIA_FlowsToPropertyId: return "UIA_FlowsToPropertyId";
    case UIA_FrameworkIdPropertyId: return "UIA_FrameworkIdPropertyId";
    case UIA_FullDescriptionPropertyId: return "UIA_FullDescriptionPropertyId";
    case UIA_HasKeyboardFocusPropertyId: return "UIA_HasKeyboardFocusPropertyId";
    case UIA_HeadingLevelPropertyId: return "UIA_HeadingLevelPropertyId";
    case UIA_HelpTextPropertyId: return "UIA_HelpTextPropertyId";
    case UIA_IsContentElementPropertyId: return "UIA_IsContentElementPropertyId";
    case UIA_IsControlElementPropertyId: return "UIA_IsControlElementPropertyId";
    case UIA_IsDataValidForFormPropertyId: return "UIA_IsDataValidForFormPropertyId";
    case UIA_IsDialogPropertyId: return "UIA_IsDialogPropertyId";
    case UIA_IsEnabledPropertyId: return "UIA_IsEnabledPropertyId";
    case UIA_IsKeyboardFocusablePropertyId: return "UIA_IsKeyboardFocusablePropertyId";
    case UIA_IsOffscreenPropertyId: return "UIA_IsOffscreenPropertyId";
    case UIA_IsPasswordPropertyId: return "UIA_IsPasswordPropertyId";
    case UIA_IsPeripheralPropertyId: return "UIA_IsPeripheralPropertyId";
    case UIA_IsRequiredForFormPropertyId: return "UIA_IsRequiredForFormPropertyId";
    case UIA_ItemStatusPropertyId: return "UIA_ItemStatusPropertyId";
    case UIA_ItemTypePropertyId: return "UIA_ItemTypePropertyId";
    case UIA_LabeledByPropertyId: return "UIA_LabeledByPropertyId";
    case UIA_LandmarkTypePropertyId: return "UIA_LandmarkTypePropertyId";
    case UIA_LevelPropertyId: return "UIA_LevelPropertyId";
    case UIA_LiveSettingPropertyId: return "UIA_LiveSettingPropertyId";
    case UIA_LocalizedControlTypePropertyId: return "UIA_LocalizedControlTypePropertyId";
    case UIA_LocalizedLandmarkTypePropertyId: return "UIA_LocalizedLandmarkTypePropertyId";
    case UIA_NamePropertyId: return "UIA_NamePropertyId";
    case UIA_NativeWindowHandlePropertyId: return "UIA_NativeWindowHandlePropertyId";
    case UIA_OptimizeForVisualContentPropertyId: return "UIA_OptimizeForVisualContentPropertyId";
    case UIA_OrientationPropertyId: return "UIA_OrientationPropertyId";
    case UIA_OutlineColorPropertyId: return "UIA_OutlineColorPropertyId";
    case UIA_OutlineThicknessPropertyId: return "UIA_OutlineThicknessPropertyId";
    case UIA_PositionInSetPropertyId: return "UIA_PositionInSetPropertyId";
    case UIA_ProcessIdPropertyId: return "UIA_ProcessIdPropertyId";
    case UIA_ProviderDescriptionPropertyId: return "UIA_ProviderDescriptionPropertyId";
    case UIA_RotationPropertyId: return "UIA_RotationPropertyId";
    case UIA_RuntimeIdPropertyId: return "UIA_RuntimeIdPropertyId";
    case UIA_SizePropertyId: return "UIA_SizePropertyId";
    case UIA_SizeOfSetPropertyId: return "UIA_SizeOfSetPropertyId";
    case UIA_VisualEffectsPropertyId: return "UIA_VisualEffectsPropertyId";
    default: return "Unknown PropertyId";
    }
}

class EventHandler :
    public IUIAutomationPropertyChangedEventHandler
{
private:
    LONG _refCount;

public:
    int _eventCount;

    //Constructor.
    EventHandler() : _refCount(1), _eventCount(0)
    {
    }

    //IUnknown methods.
    ULONG STDMETHODCALLTYPE AddRef()
    {
        ULONG ret = InterlockedIncrement(&_refCount);
        return ret;
    }

    ULONG STDMETHODCALLTYPE Release()
    {
        ULONG ret = InterlockedDecrement(&_refCount);
        if (ret == 0)
        {
            delete this;
            return 0;
        }
        return ret;
    }

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppInterface)
    {
        if (riid == __uuidof(IUnknown))
            *ppInterface = static_cast<IUIAutomationPropertyChangedEventHandler*>(this);
        else if (riid == __uuidof(IUIAutomationPropertyChangedEventHandler))
            *ppInterface = static_cast<IUIAutomationPropertyChangedEventHandler*>(this);
        else
        {
            *ppInterface = NULL;
            return E_NOINTERFACE;
        }
        this->AddRef();
        return S_OK;
    }

    // IUIAutomationPropertyChangedEventHandler methods.
    HRESULT STDMETHODCALLTYPE HandlePropertyChangedEvent(IUIAutomationElement* pSender, PROPERTYID propertyID, VARIANT newValue)
    {
        _eventCount++;
        printf("Property: %s changed, count: %d\n", AutomationPropertyIdToString(propertyID), _eventCount);
        return S_OK;
    }
};

int main(int argc, char* argv[])
{
    puts("Move cursor to the window... (wait for 3 seconds)");
    Sleep(3000);

    POINT p;
    GetCursorPos(&p);

    HWND hwnd = WindowFromPoint(p);
    wchar_t title[MAX_PATH]{};
    GetWindowText(hwnd, title, std::size(title));
    _putws(std::format(L"Listening events on: {:X}, title: {}", reinterpret_cast<uint64_t>(hwnd), title).data());

    IUIAutomationElement* pTargetElement = NULL;


    CoInitializeEx(NULL, COINIT_MULTITHREADED);

    IUIAutomation* pAutomation = NULL;
    CoCreateInstance(__uuidof(CUIAutomation), NULL, CLSCTX_INPROC_SERVER, __uuidof(IUIAutomation), (void**)&pAutomation);


    EventHandler* pEHTemp = new EventHandler();

    PROPERTYID pPIDProperties[] = { UIA_NamePropertyId, UIA_FrameworkIdPropertyId, UIA_AutomationIdPropertyId };

    pAutomation->ElementFromHandle(hwnd, &pTargetElement);
    wprintf(L"-Adding Event Handler.\n");
    pAutomation->AddPropertyChangedEventHandlerNativeArray(pTargetElement, TreeScope_Subtree, NULL, (IUIAutomationPropertyChangedEventHandler*)pEHTemp, pPIDProperties, sizeof(pPIDProperties) / sizeof(pPIDProperties[0]));
    wprintf(L"-Press any key to remove event handler and exit\n");
    getchar();

    wprintf(L"-Removing Event Handler.\n");
    pAutomation->RemovePropertyChangedEventHandler(pTargetElement, (IUIAutomationPropertyChangedEventHandler*)pEHTemp);

    // Release resources and terminate.
cleanup:
    if (pEHTemp != NULL)
        pEHTemp->Release();

    if (pTargetElement != NULL)
        pTargetElement->Release();

    if (pAutomation != NULL)
        pAutomation->Release();

    CoUninitialize();
}