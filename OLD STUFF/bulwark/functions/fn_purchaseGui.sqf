/**
*  fn_purchaseGui
*
*  Displays GUI for purchases from the bullwark box.
*
*  Domain: Client
**/

disableSerialization;

_listFormat = "%1 - %2";


createDialog "startBox_Dialog";
waitUntil {!isNull (findDisplay 9999);};

_ctrl = (findDisplay 9999) displayCtrl 1500;
{
    _ctrl lbAdd format [_listFormat, _x select 0, _x select 1],;
} forEach BLWK_buildableObjects_array;








_ctrl = (findDisplay 9999) displayCtrl 1501;
if (BLWK_supportDishFound) then {
  {
      _ctrl lbAdd format [_listFormat, _x select 0, _x select 1],;
  } forEach BLWK_supports_array;
}else{
  _ctrl lbAdd " ";
  _ctrl lbAdd "";
  _ctrl lbAdd "         A Satellite Dish must be found";
  _ctrl lbAdd "             to unlock Support Menu";
};


((findDisplay 9999) displayCtrl 1500) ctrlAddEventHandler ['LBSelChanged', {
_index = lbCurSel 1500;
_picture = getText (configFile >> "CfgVehicles" >> ((BLWK_buildableObjects_array select _index) select 2) >> "editorPreview");
/**   getText ((BLWK_buildableObjects_array select _index) select 2)    editorPreview = "EFM_modular_base\data\preview\EFM_beam_wood_v_1_5m.jpg";**/
ctrlSetText [1502, _picture];

}]