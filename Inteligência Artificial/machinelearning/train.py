from torch import no_grad
from torch.utils.data import DataLoader


"""
Functions you should use.
Please avoid importing any other functions or modules.
Your code will not pass if the gradescope autograder detects any changed imports
"""
from torch import optim, tensor
from losses import regression_loss, digitclassifier_loss, languageid_loss, digitconvolution_Loss
from torch import movedim


"""
##################
### QUESTION 1 ###
##################
"""


def train_perceptron(model, dataset):
    """
    Train the perceptron until convergence.
    You can iterate through DataLoader in order to 
    retrieve all the batches you need to train on.

    Each sample in the dataloader is in the form {'x': features, 'label': label} where label
    is the item we need to predict based off of its features.
    """
    with no_grad():
        dataloader = DataLoader(dataset, batch_size=1, shuffle=True)
        "*** YOUR CODE HERE ***"
        dataloader = DataLoader(dataset, batch_size=1, shuffle=True)

        with no_grad():
            while True:
                mistakes = 0

                for batch in dataloader:
                    x = batch['x']
                    y = batch['label']

                    pred = model.get_prediction(x.squeeze(0))

                    if pred != y.item():
                        mistakes += 1
                        model.w.data += y.item() * x.squeeze(0)

                if mistakes == 0:
                    break

def train_regression(model, dataset):
    """
    Trains the model.

    In order to create batches, create a DataLoader object and pass in `dataset` as well as your required 
    batch size. You can look at PerceptronModel as a guideline for how you should implement the DataLoader

    Each sample in the dataloader object will be in the form {'x': features, 'label': label} where label
    is the item we need to predict based off of its features.

    Inputs:
        model: Pytorch model to use
        dataset: a PyTorch dataset object containing data to be trained on
        
    """
    "*** YOUR CODE HERE ***"
    dataloader = DataLoader(dataset, batch_size=32, shuffle=True)

    optimizer = optim.Adam(model.parameters(), lr=0.01)

    for epoch in range(1000):
        total_loss = 0.0
        for batch in dataloader:
            x = batch['x']
            y = batch['label']

            optimizer.zero_grad()

            y_pred = model(x)

            loss = regression_loss(y_pred, y)

            loss.backward()
            optimizer.step()

            total_loss += loss.item()

        avg_loss = total_loss / len(dataloader)
        print(f'Epoch {epoch+1}, Loss: {avg_loss:.4f}')

        if avg_loss < 0.02:
            break

def train_digitclassifier(model, dataset):
    """
    Trains the model.
    """
    model.train()
    """ YOUR CODE HERE """
    train_loader = DataLoader(dataset.train_data(), batch_size=64, shuffle=True)
    optimizer = optim.Adam(model.parameters(), lr=1e-3)

    for epoch in range(10):
        model.train()
        for x_batch, y_batch in train_loader:
            optimizer.zero_grad()
            y_pred = model(x_batch)
            loss = digitclassifier_loss(y_pred, y_batch)
            loss.backward()
            optimizer.step()

        acc = dataset.get_validation_accuracy(model)
        print(f"Epoch {epoch + 1}, Validation Accuracy: {acc:.4f}")
        if acc >= 0.98:
            break

def train_languageid(model, dataset):
    """
    Trains the model.

    Note that when you iterate through dataloader, each batch will returned as its own vector in the form
    (batch_size x length of word x self.num_chars). However, in order to run multiple samples at the same time,
    get_loss() and run() expect each batch to be in the form (length of word x batch_size x self.num_chars), meaning
    that you need to switch the first two dimensions of every batch. This can be done with the movedim() function 
    as follows:

    movedim(input_vector, initial_dimension_position, final_dimension_position)

    For more information, look at the pytorch documentation of torch.movedim()
    """
    model.train()
    "*** YOUR CODE HERE ***"
    dataloader = DataLoader(dataset, batch_size=64, shuffle=True)
    optimizer = optim.Adam(model.parameters(), lr=1e-3)

    for epoch in range(10):
        for x_batch, y_batch in dataloader:
            x_batch = movedim(x_batch, 0, 1)
            y_pred = model(list(x_batch))

            loss = languageid_loss(y_pred, y_batch)

            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

        val_acc = dataset.get_validation_accuracy(model)
        print(f"Epoch {epoch + 1}: Val Accuracy = {val_acc:.4f}")
        if val_acc >= 0.82:
            break

def Train_DigitConvolution(model, dataset):
    """
    Trains the model.
    """
    """ YOUR CODE HERE """
    dataloader = DataLoader(dataset, batch_size=64, shuffle=True)
    optimizer = optim.Adam(model.parameters(), lr=1e-3)

    for epoch in range(10):
        model.train()
        total_loss = 0
        correct = 0
        total = 0

        for batch in dataloader:
            x = batch['x']
            y = batch['label']

            optimizer.zero_grad()
            y_pred = model(x)
            loss = digitconvolution_Loss(y_pred, y)
            loss.backward()
            optimizer.step()

            total_loss += loss.item()
            _, predicted = y_pred.max(1)
            correct += predicted.eq(y).sum().item()
            total += y.size(0)

        acc = correct / total
        print(f'Epoch {epoch+1}, Loss: {total_loss/len(dataloader):.4f}, Accuracy: {acc:.4f}')

        if acc >= 0.8:
            break
