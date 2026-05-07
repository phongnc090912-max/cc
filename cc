local key = {string.char(112,104,111,110,103,100,101,112,116,114,97,105,48,57,48,57,49,50,33)}

local Rayfield = loadstring(game:HttpGet('https://sirius.menu/rayfield'))()

local Window = Rayfield:CreateWindow({
   Name = "Vo1d scripts",
   Icon = 0,        
   LoadingTitle = "Exploit tool",
   LoadingSubtitle = "by Vo1d",
   ShowText = "Vo1d",
   Theme = "AmberGlow",

   ToggleUIKeybind = "K",

   DisableRayfieldPrompts = false,
   DisableBuildWarnings = false,

   ConfigurationSaving = {
      Enabled = false,
      FolderName = nil,
      FileName = "Big Hub"
   },

   KeySystem = true,
   KeySettings = {
      Title = "Vo1d | Key",
      Subtitle = "Key System",
      Note = "Get the key on https://docs.google.com/document/d/16iatNXWzFK39oa7oYVQ7656TTHumxM2pPDUw7Wc3iVI/edit?hl=vi&tab=t.0",
      FileName = "Key",
      SaveKey = true,
      GrabKeyFromSite = false,
      Key = key
   }
})

local MainTab = Window:CreateTab("Movement", nil)
local FlyTab = Window:CreateTab("Fly", nil)

Rayfield:Notify({
   Title = "TOOL EXECUTED",
   Content = "The tool is running",
   Duration = 5,
   Image = nil,
   Action = {
      Ignore = {
         Name = "Okay!",
         Callback = function()
            print("The user tapped Okay!")
         end
      }
   }
})

local player = game.Players.LocalPlayer
local speed = 16

local function bindHumanoid(humanoid)
   humanoid.WalkSpeed = speed
   humanoid:GetPropertyChangedSignal("WalkSpeed"):Connect(function()
      if humanoid.WalkSpeed ~= speed then
         humanoid.WalkSpeed = speed
      end
   end)
end

local function onCharacterSpeed(char)
   local humanoid = char:WaitForChild("Humanoid")
   bindHumanoid(humanoid)
end

if player.Character then
   onCharacterSpeed(player.Character)
end
player.CharacterAdded:Connect(onCharacterSpeed)

local SpeedSlider = MainTab:CreateSlider({
   Name = "WALKSPEED",
   Range = {10, 360},
   Increment = 1,
   Suffix = "speed",
   CurrentValue = 16,
   Flag = "Slider1", 
   Callback = function(Value)
      speed = Value
      local char = player.Character
      if char then
         local hum = char:FindFirstChild("Humanoid")
         if hum then hum.WalkSpeed = speed end
      end
   end,
})

local UIS = game:GetService("UserInputService")
local RunService = game:GetService("RunService")

local jumpPower = 50

local function bindHumanoid(humanoid)
   humanoid.UseJumpPower = true
   humanoid.JumpPower = jumpPower
   humanoid:GetPropertyChangedSignal("JumpPower"):Connect(function()
      if humanoid.UseJumpPower and humanoid.JumpPower ~= jumpPower then
         humanoid.JumpPower = jumpPower
      end
   end)
end

local function onCharacterJumpPower(char)
   local humanoid = char:WaitForChild("Humanoid")
   bindHumanoid(humanoid)
end

if player.Character then
   onCharacterJumpPower(player.Character)
end
player.CharacterAdded:Connect(onCharacterJumpPower)

local JumpPowerSlider = MainTab:CreateSlider({
   Name = "Jump power",
   Range = {10, 360},
   Increment = 1,
   Suffix = "Power",
   CurrentValue = 50,
   Callback = function(Value)
      jumpPower = Value
      local char = player.Character
      if char then
         local hum = char:FindFirstChild("Humanoid")
         if hum then
            hum.UseJumpPower = true
            hum.JumpPower = jumpPower
         end
      end
   end
})

local infJump = false
local characterJumpinf
local humanoid

local function bindCharacterJumpinf(char)
   characterJumpinf = char
   humanoid = char:WaitForChild("Humanoid")
end

local function onCharacterJumpinf(char)
   bindCharacterJumpinf(char)
end

if player.Character then
    onCharacterJumpinf(player.Character)
end
player.CharacterAdded:Connect(onCharacterJumpinf)

local function setupInfJump()
   UIS.JumpRequest:Connect(function()
      if infJump and humanoid then
         humanoid:ChangeState(Enum.HumanoidStateType.Jumping)
      end
   end)
end

setupInfJump()

local INFJumpToggle = MainTab:CreateToggle({
   Name = "INF Jump",
   CurrentValue = false,
   Callback = function(v)
      infJump = v

   end
})

local noclip = false
local characterNoclip

local function bindCharacterNoclip(char)
   characterNoclip = char
   root = char:WaitForChild("HumanoidRootPart")
end

local function onCharacterNoclip(char)
   bindCharacterNoclip(char)
end

if player.Character then
    onCharacterNoclip(player.Character)
end
player.CharacterAdded:Connect(onCharacterNoclip)

local function applyNoclip()
   if not noclip or not characterNoclip then return end

   for _, v in pairs(characterNoclip:GetDescendants()) do
      if v:IsA("BasePart") then
         v.CanCollide = false
      end
   end
end

RunService.Stepped:Connect(applyNoclip)

local function resetNoclip()
   if not characterNoclip then return end

   for _, v in pairs(characterNoclip:GetDescendants()) do
      if v:IsA("BasePart") then
         v.CanCollide = true
      end
   end
end

local noclipToggle = FlyTab:CreateToggle({
   Name = "Noclip",
   CurrentValue = false,
   Callback = function(v)
      noclip = v
      if not v then
         resetNoclip()
      end
   end
})

local fly = false
local flyspeed = 2

local root
local humanoid

local camera = workspace.CurrentCamera

local keys = {
   W = false,
   A = false,
   S = false,
   D = false
}

--// CHARACTER
local function bindCharacterFly(char)
   root = char:WaitForChild("HumanoidRootPart")
   humanoid = char:WaitForChild("Humanoid")
end

local function onCharacterFly(char)
   bindCharacterFly(char)
end

if player.Character then
   onCharacterFly(player.Character)
end

player.CharacterAdded:Connect(onCharacterFly)

--// INPUT
UIS.InputBegan:Connect(function(input, gpe)
   if gpe then return end

   if input.KeyCode == Enum.KeyCode.W then
      keys.W = true
   end

   if input.KeyCode == Enum.KeyCode.A then
      keys.A = true
   end

   if input.KeyCode == Enum.KeyCode.S then
      keys.S = true
   end

   if input.KeyCode == Enum.KeyCode.D then
      keys.D = true
   end
end)

UIS.InputEnded:Connect(function(input)
   if input.KeyCode == Enum.KeyCode.W then
      keys.W = false
   end

   if input.KeyCode == Enum.KeyCode.A then
      keys.A = false
   end

   if input.KeyCode == Enum.KeyCode.S then
      keys.S = false
   end

   if input.KeyCode == Enum.KeyCode.D then
      keys.D = false
   end
end)

--// APPLY
local function applyFly()
   if not fly then return end
   if not root then return end

   local moveDirection = Vector3.zero

   local lookVector = camera.CFrame.LookVector
   local rightVector = camera.CFrame.RightVector

   if keys.W then
      moveDirection += lookVector
   end

   if keys.S then
      moveDirection -= lookVector
   end

   if keys.A then
      moveDirection -= rightVector
   end

   if keys.D then
      moveDirection += rightVector
   end

   if moveDirection.Magnitude > 0 then
      moveDirection = moveDirection.Unit
   end

   root.CFrame =
      root.CFrame +
      (moveDirection * flyspeed)
end

RunService.RenderStepped:Connect(applyFly)

--// RESET
local function resetFly()
   if humanoid then
      humanoid.PlatformStand = false
   end
end

local flyToggle = FlyTab:CreateToggle({
   Name = "Fly",
   CurrentValue = false,
   Callback = function(v)
      fly = v
      if not v then
         resetFly()
      end
   end
})

local flyspeedSlider = FlyTab:CreateSlider({
   Name = "Fly speed",
   Range = {10, 360},
   Increment = 1,
   Suffix = "speed",
   CurrentValue = 50,
   Callback = function(v)
      flyspeed = v
   end
})
