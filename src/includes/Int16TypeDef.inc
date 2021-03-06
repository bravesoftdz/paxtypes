
type
   { TInt16 }

  TInt16 = class(TInterfacedObject, IInt16,ISerializable)
  private
    function GetValue: Int16;
    procedure SetValue(AValue: Int16);
  protected
    FValue: Int16;
  public
    constructor Create(aValue: Int16);
    property Value : Int16 read GetValue write SetValue;
  end;


operator := (aValue: Int16)        : IInt16;
begin
  result := TInt16.Create(aValue);
end;

operator Explicit(aValue: Int16)    : IInt16;
begin
  result := TInt16.Create(aValue);
end;

operator Explicit(aValue: IInt16)   : Int16;
begin
  result := aValue.Value;
end;

operator+(const Left: IInt16; const right: IInt16)    : Int16;
begin
  if not assigned(left) then Raise ENullPointerException.Create('Addition :Left parameter is nil');
  if not assigned(right)then Raise ENullPointerException.Create('Addition :Right parameter is nil');
  result := left.value + right.value;
end;
operator + (const Left : IInt16;const right : IInt16) :  IInt16;
begin
  if not assigned(left) then Raise ENullPointerException.Create('Addition :Left parameter is nil');
  if not assigned(right)then Raise ENullPointerException.Create('Addition :Right parameter is nil');
  result := left.value + right.value;
end;

operator+(const Left: IInt16; const right: Int16)     : Int16;
begin
  if not assigned(left) then Raise ENullPointerException.Create('Addition :Left parameter is nil');
  result := left.value + right;
end;

operator+(const Left: Int16; const right: IInt16)     : Int16;
begin
  if not assigned(right)then Raise ENullPointerException.Create('Addition :Right parameter is nil');
  result := left+ right.value;
end;

{ TInt16 }

function TInt16.GetValue: Int16;
begin
  result := FValue;
end;

procedure TInt16.SetValue(AValue: Int16);
begin
  if FValue=AValue then Exit;
  FValue:=AValue;
end;

constructor TInt16.Create(aValue: Int16);
begin
  FValue:= aValue;
end;
